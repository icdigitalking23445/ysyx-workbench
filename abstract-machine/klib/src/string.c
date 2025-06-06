#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

/**
 * 计算字符串长度，不包含终止符 '\0'
 * 返回 s 中连续非 '\0' 字符的个数。
 */
size_t strlen(const char *s) {
  const char *p = s;
  while (*p) p++;
  return (size_t)(p - s);
}

/**
 * 将 src 所指向的 C 字符串（含 '\0'）拷贝到 dst。
 * 返回 dst 的指针。
 */
char *strcpy(char *dst, const char *src) {
  char *orig = dst;
  while ((*dst++ = *src++) != '\0') { }
  return orig;
}

/**
 * 将 src 中最多 n 个字符拷贝到 dst。
 * 如果 src 长度不足 n，会在末尾用 '\0' 补足；
 * 如果 src 长度 ≥ n，则只拷贝前 n 个字符且不额外添加 '\0'。
 * 返回 dst。
 */
char *strncpy(char *dst, const char *src, size_t n) {
  size_t i = 0;
  /* 先拷贝 src 中的字符，直到达到 n 或遇到 '\0' */
  for (; i < n && src[i] != '\0'; i++) {
    dst[i] = src[i];
  }
  /* 如果还没到 n，剩余部分全部补 '\0' */
  for (; i < n; i++) {
    dst[i] = '\0';
  }
  return dst;
}

/**
 * 将 src 拼接到 dst 末尾（dst 必须以 '\0' 结尾并有足够空间）。
 * 返回 dst。
 */
char *strcat(char *dst, const char *src) {
  char *p = dst + strlen(dst);
  while ((*p++ = *src++) != '\0') { }
  return dst;
}

/**
 * 按字典序比较 s1 和 s2。
 * 如果 s1<s2 返回 <0；s1==s2 返回 0；s1>s2 返回 >0。
 */
int strcmp(const char *s1, const char *s2) {
  while (*s1 && (*s1 == *s2)) {
    s1++;
    s2++;
  }
  return (int)((unsigned char)*s1 - (unsigned char)*s2);
}

/**
 * 限制比较最多 n 个字符。
 * 如果在 n 个字符内 s1<s2 返回 <0；相等返回 0；s1>s2 返回 >0。
 * 不足 n 个字符时遇到 '\0' 即结束比较。
 */
int strncmp(const char *s1, const char *s2, size_t n) {
  size_t i = 0;
  for (; i < n && s1[i] && (s1[i] == s2[i]); i++) {
    /* 什么也不做，只是跳到下一个字符 */
  }
  if (i == n) {
    return 0;
  }
  return (int)((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/**
 * 将 s 开始的连续 n 个字节设置为 (unsigned char)c。
 * 返回 s。
 */
void *memset(void *s, int c, size_t n) {
  unsigned char *p = (unsigned char*)s;
  unsigned char uc = (unsigned char)c;
  for (size_t i = 0; i < n; i++) {
    p[i] = uc;
  }
  return s;
}

/**
 * 在 dst 和 src 区间可能重叠的情况下，将 src 前 n 个字节拷贝到 dst。
 * 如果 dst<src，按从前往后拷；如果 dst>src，按从后往前拷。
 * 返回 dst。
 */
void *memmove(void *dst, const void *src, size_t n) {
  unsigned char *d = (unsigned char *)dst;
  const unsigned char *s = (const unsigned char *)src;
  if (d < s) {
    /* 从前往后拷贝 */
    for (size_t i = 0; i < n; i++) {
      d[i] = s[i];
    }
  } else if (d > s) {
    /* 从后往前拷贝 */
    for (size_t i = n; i > 0; i--) {
      d[i - 1] = s[i - 1];
    }
  }
  /* 如果 d == s，本身就是同一块内存，无需操作 */
  return dst;
}

/**
 * 假设 dst 与 in 内存区域不重叠，直接从 in 拷贝 n 个字节到 out。
 * 返回 out。
 */
void *memcpy(void *out, const void *in, size_t n) {
  unsigned char *d = (unsigned char *)out;
  const unsigned char *s = (const unsigned char *)in;
  for (size_t i = 0; i < n; i++) {
    d[i] = s[i];
  }
  return out;
}

/**
 * 按字节比较 s1 和 s2 开头的 n 个字节。
 * 如果 s1<s2 返回 <0；相等返回 0；s1>s2 返回 >0。
 */
int memcmp(const void *s1, const void *s2, size_t n) {
  const unsigned char *p1 = (const unsigned char *)s1;
  const unsigned char *p2 = (const unsigned char *)s2;
  for (size_t i = 0; i < n; i++) {
    if (p1[i] != p2[i]) {
      return (int)(p1[i] - p2[i]);
    }
  }
  return 0;
}

#endif
