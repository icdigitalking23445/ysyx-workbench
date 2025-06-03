file://<WORKSPACE>/src/main/scala/top.scala
### java.lang.OutOfMemoryError: Java heap space

occurred in the presentation compiler.

presentation compiler configuration:


action parameters:
offset: 182
uri: file://<WORKSPACE>/src/main/scala/top.scala
text:
```scala
package npc
import Chisel3._
import chisel3.util._

class Top extends Module {
  val io = IO(new Bundle {
    val in = Input(UInt(32.W))
    val out = Output(UInt(32.W))
  })
  
    @@val regFile = Module(new RegFile)
    val IFU = Module(new IFU)
    val IDU = Module(new IDU)
    val EXU = Module(new EXU)
    val pc = RegInit(0x80000000, 32.W) // Initial PC value
    val instruction = Wire(UInt(32.W))
    val decode =    

    IFU.io.pc := pc
    instruction := IFU.io.instruction

    IDU.io.instruction := instruction

}

```



#### Error stacktrace:

```

```
#### Short summary: 

java.lang.OutOfMemoryError: Java heap space