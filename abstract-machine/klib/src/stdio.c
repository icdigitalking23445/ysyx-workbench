#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

/**
 * 内部助手：把无符号 32 位整数转换为十进制字符串，返回写入长度
 * @param buf  目标缓冲区，至少能容纳 10 位 + '\0'
 * @param u    无符号整数
 */
static int u32_to_dec(char *buf, uint32_t u) {
  /* 特判 0 */
  if (u == 0) {
    buf[0] = '0';
    buf[1] = '\0';
    return 1;
  }
  char tmp[11];
  int idx = 0;
  while (u > 0) {
    tmp[idx++] = (char)('0' + (u % 10));
    u /= 10;
  }
  /* 逆序写到 buf */
  for (int i = 0; i < idx; i++) {
    buf[i] = tmp[idx - 1 - i];
  }
  buf[idx] = '\0';
  return idx;
}

/**
 * 内部助手：把有符号 32 位整数转换为十进制字符串，返回写入长度
 * @param buf  目标缓冲区，至少能容纳 11 位（包括符号）+ '\0'
 * @param d    有符号整数
 */
static int i32_to_dec(char *buf, int32_t d) {
  if (d < 0) {
    buf[0] = '-';
    int len = u32_to_dec(buf + 1, (uint32_t)(-d));
    return len + 1;
  } else {
    return u32_to_dec(buf, (uint32_t)d);
  }
}

/**
 * 内部助手：把无符号 32 位整数当作 16 进制转换为字符串，返回写入长度
 * @param buf  目标缓冲区，至少能容纳 8 位 + '\0'
 * @param u    无符号整数
 * @param width  宽度（写满多少位，不足则高位补 '0'，例如 width=8 -> 总共输出 8 位十六进制）
 */
static int u32_to_hex(char *buf, uint32_t u, int width) {
  /* 一般 width=8 来打印完整 32 位，或 width=0 表示不补零，按实际位数 */
  char tmp[9];
  int idx = 0;
  if (u == 0) {
    tmp[idx++] = '0';
  } else {
    while (u > 0) {
      uint32_t digit = u & 0xF;
      tmp[idx++] = (char)(digit < 10 ? ('0' + digit) : ('a' + (digit - 10)));
      u >>= 4;
    }
  }
  int total = idx;
  if (width > total) {
    /* 用 '0' 补齐到 width */
    for (int i = total; i < width; i++) {
      buf[i] = '0';
    }
  }
  /* 逆序写入 tmp */
  for (int i = 0; i < total; i++) {
    buf[(width > total ? width : total) - 1 - i] = tmp[i];
  }
  int out_len = (width > total ? width : total);
  buf[out_len] = '\0';
  return out_len;
}

/**
 * vsprintf：将格式化后的字符串写到 out，调用者保证 out 空间足够大（典型 ≥1024 字节）。
 * 支持格式： %c, %d, %u, %x, %s, %p, %% 
 * 其中 %p 等同于 width=8 的 %x（以 32 位模式打印地址）。
 * @param out  输出缓冲区
 * @param fmt  格式字符串
 * @param ap   va_list 参数
 * @return     写入到 out 的字符数（不含末尾 '\0'）
 */
int vsprintf(char *out, const char *fmt, va_list ap) {
  char *p = out;
  for (const char *f = fmt; *f; f++) {
    if (*f != '%') {
      *p++ = *f;
      continue;
    }
    /* 遇到 '%' */
    f++;
    if (*f == '\0') break;
    if (*f == '%') {
      *p++ = '%';
    } else if (*f == 'c') {
      char c = (char)va_arg(ap, int);
      *p++ = c;
    } else if (*f == 'd') {
      int32_t d = va_arg(ap, int);
      char bufnum[12];
      int len = i32_to_dec(bufnum, d);
      memcpy(p, bufnum, len);
      p += len;
    } else if (*f == 'u') {
      uint32_t u = va_arg(ap, unsigned int);
      char bufnum[11];
      int len = u32_to_dec(bufnum, u);
      memcpy(p, bufnum, len);
      p += len;
    } else if (*f == 'x') {
      uint32_t u = va_arg(ap, unsigned int);
      char bufnum[9];
      int len = u32_to_hex(bufnum, u, 0);
      memcpy(p, bufnum, len);
      p += len;
    } else if (*f == 'p') {
      /* 指针，打印为 width=8 的 16 进制 */
      uint32_t u = (uint32_t)(uintptr_t)va_arg(ap, void *);
      char bufnum[9];
      int len = u32_to_hex(bufnum, u, 8);
      memcpy(p, bufnum, len);
      p += len;
    } else if (*f == 's') {
      const char *s = va_arg(ap, const char *);
      size_t slen = strlen(s);
      memcpy(p, s, slen);
      p += slen;
    } else {
      /* 未支持的格式，直接把 '%' 及后续字符原样输出 */
      *p++ = '%';
      *p++ = *f;
    }
  }
  *p = '\0';
  return (int)(p - out);
}

/**
 * sprintf：格式化写到 out，不限制长度。
 */
int sprintf(char *out, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  int len = vsprintf(out, fmt, ap);
  va_end(ap);
  return len;
}

/**
 * snprintf：限制写入不超过 n-1 字节，最后以 '\0' 结尾。
 */
int snprintf(char *out, size_t n, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  int written = 0;
  if (n > 0) {
    /* 简单做法：先写进临时缓冲，再截断拷贝 */
    char tmp[1024];
    int len = vsprintf(tmp, fmt, ap);
    int copy_len = (len < (int)(n - 1)) ? len : (int)(n - 1);
    memcpy(out, tmp, copy_len);
    out[copy_len] = '\0';
    written = copy_len;
  }
  va_end(ap);
  return written;
}

/**
 * vsnprintf：同样限制写入不超过 n-1 字节。
 */
int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  int written = 0;
  if (n > 0) {
    char tmp[1024];
    int len = vsprintf(tmp, fmt, ap);
    int copy_len = (len < (int)(n - 1)) ? len : (int)(n - 1);
    memcpy(out, tmp, copy_len);
    out[copy_len] = '\0';
    written = copy_len;
  }
  return written;
}

/**
 * printf：先把格式化结果写到缓冲区，然后通过 _putc 逐字符输出。
 * 返回最终输出字符数。
 */
int printf(const char *fmt, ...) {
  char buf[1024];
  va_list ap;
  va_start(ap, fmt);
  int len = vsprintf(buf, fmt, ap);
  va_end(ap);
  for (int i = 0; i < len; i++) {
    putch(buf[i]);
  }
  return len;
}

#endif
