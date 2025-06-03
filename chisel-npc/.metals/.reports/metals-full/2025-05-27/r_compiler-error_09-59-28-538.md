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
dotty.tools.dotc.util.WeakHashSet.<init>(WeakHashSet.scala:54)
	dotty.tools.dotc.core.Uniques.<init>(Uniques.scala:11)
	dotty.tools.dotc.core.Contexts$ContextState.<init>(Contexts.scala:969)
	dotty.tools.dotc.core.Contexts$ContextBase.<init>(Contexts.scala:862)
	dotty.tools.dotc.Driver.initCtx(Driver.scala:60)
	dotty.tools.dotc.interactive.InteractiveDriver.<init>(InteractiveDriver.scala:34)
	dotty.tools.pc.CachingDriver.<init>(CachingDriver.scala:30)
	dotty.tools.pc.ScalaPresentationCompiler.$init$$$anonfun$1(ScalaPresentationCompiler.scala:85)
```
#### Short summary: 

java.lang.OutOfMemoryError: Java heap space