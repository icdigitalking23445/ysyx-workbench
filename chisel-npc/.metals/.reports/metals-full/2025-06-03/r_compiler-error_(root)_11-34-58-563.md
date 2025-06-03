file://<WORKSPACE>/src/main/scala/top.scala
### scala.ScalaReflectionException: value funct3 is not a method

occurred in the presentation compiler.

presentation compiler configuration:
Scala version: 2.12.13
Classpath:
<WORKSPACE>/.bloop/root/bloop-bsp-clients-classes/classes-Metals-mQ5sz3jcTMeOxlm8SuIMKA== [exists ], <HOME>/.cache/bloop/semanticdb/com.sourcegraph.semanticdb-javac.0.10.4/semanticdb-javac-0.10.4.jar [exists ], <HOME>/.cache/coursier/v1/https/repo1.maven.org/maven2/org/scala-lang/scala-library/2.12.13/scala-library-2.12.13.jar [exists ], <HOME>/.cache/coursier/v1/https/repo1.maven.org/maven2/edu/berkeley/cs/chisel3_2.12/3.5.3/chisel3_2.12-3.5.3.jar [exists ], <HOME>/.cache/coursier/v1/https/repo1.maven.org/maven2/edu/berkeley/cs/chisel3-macros_2.12/3.5.3/chisel3-macros_2.12-3.5.3.jar [exists ], <HOME>/.cache/coursier/v1/https/repo1.maven.org/maven2/edu/berkeley/cs/chisel3-core_2.12/3.5.3/chisel3-core_2.12-3.5.3.jar [exists ], <HOME>/.cache/coursier/v1/https/repo1.maven.org/maven2/org/scala-lang/scala-reflect/2.12.13/scala-reflect-2.12.13.jar [exists ], <HOME>/.cache/coursier/v1/https/repo1.maven.org/maven2/com/lihaoyi/os-lib_2.12/0.8.0/os-lib_2.12-0.8.0.jar [exists ], <HOME>/.cache/coursier/v1/https/repo1.maven.org/maven2/edu/berkeley/cs/firrtl_2.12/1.5.3/firrtl_2.12-1.5.3.jar [exists ], <HOME>/.cache/coursier/v1/https/repo1.maven.org/maven2/com/lihaoyi/geny_2.12/0.7.0/geny_2.12-0.7.0.jar [exists ], <HOME>/.cache/coursier/v1/https/repo1.maven.org/maven2/org/antlr/antlr4-runtime/4.9.3/antlr4-runtime-4.9.3.jar [exists ], <HOME>/.cache/coursier/v1/https/repo1.maven.org/maven2/com/google/protobuf/protobuf-java/3.18.0/protobuf-java-3.18.0.jar [exists ], <HOME>/.cache/coursier/v1/https/repo1.maven.org/maven2/com/github/scopt/scopt_2.12/3.7.1/scopt_2.12-3.7.1.jar [exists ], <HOME>/.cache/coursier/v1/https/repo1.maven.org/maven2/net/jcazevedo/moultingyaml_2.12/0.4.2/moultingyaml_2.12-0.4.2.jar [exists ], <HOME>/.cache/coursier/v1/https/repo1.maven.org/maven2/org/json4s/json4s-native_2.12/3.6.12/json4s-native_2.12-3.6.12.jar [exists ], <HOME>/.cache/coursier/v1/https/repo1.maven.org/maven2/org/apache/commons/commons-text/1.9/commons-text-1.9.jar [exists ], <HOME>/.cache/coursier/v1/https/repo1.maven.org/maven2/io/github/alexarchambault/data-class_2.12/0.2.5/data-class_2.12-0.2.5.jar [exists ], <HOME>/.cache/coursier/v1/https/repo1.maven.org/maven2/com/github/nscala-time/nscala-time_2.12/2.22.0/nscala-time_2.12-2.22.0.jar [exists ], <HOME>/.cache/coursier/v1/https/repo1.maven.org/maven2/org/yaml/snakeyaml/1.26/snakeyaml-1.26.jar [exists ], <HOME>/.cache/coursier/v1/https/repo1.maven.org/maven2/org/json4s/json4s-core_2.12/3.6.12/json4s-core_2.12-3.6.12.jar [exists ], <HOME>/.cache/coursier/v1/https/repo1.maven.org/maven2/org/apache/commons/commons-lang3/3.11/commons-lang3-3.11.jar [exists ], <HOME>/.cache/coursier/v1/https/repo1.maven.org/maven2/joda-time/joda-time/2.10.1/joda-time-2.10.1.jar [exists ], <HOME>/.cache/coursier/v1/https/repo1.maven.org/maven2/org/joda/joda-convert/2.2.0/joda-convert-2.2.0.jar [exists ], <HOME>/.cache/coursier/v1/https/repo1.maven.org/maven2/org/json4s/json4s-ast_2.12/3.6.12/json4s-ast_2.12-3.6.12.jar [exists ], <HOME>/.cache/coursier/v1/https/repo1.maven.org/maven2/org/json4s/json4s-scalap_2.12/3.6.12/json4s-scalap_2.12-3.6.12.jar [exists ], <HOME>/.cache/coursier/v1/https/repo1.maven.org/maven2/com/thoughtworks/paranamer/paranamer/2.8/paranamer-2.8.jar [exists ]
Options:
-deprecation -feature -unchecked -Xfatal-warnings -language:reflectiveCalls -Yrangepos -Xplugin-require:semanticdb


action parameters:
uri: file://<WORKSPACE>/src/main/scala/top.scala
text:
```scala
package npc
import chisel3._
import chisel3.util._

class top extends Module{
val io = IO (new  Bundle {
    val instruction = Input(UInt(32.W)) // Input instruction
    val rs1 = Output(UInt(5.W)) // Source register 1
    val rs2 = Output(UInt(5.W)) // Source register 2
    val rd = Output(UInt(5.W)) // Destination register
    val funct3 = Output(UInt(3.W)) /



  }
}
```



#### Error stacktrace:

```
scala.reflect.api.Symbols$SymbolApi.asMethod(Symbols.scala:240)
	scala.reflect.api.Symbols$SymbolApi.asMethod$(Symbols.scala:234)
	scala.reflect.internal.Symbols$SymbolContextApiImpl.asMethod(Symbols.scala:100)
	scala.tools.nsc.typechecker.ContextErrors$TyperContextErrors$TyperErrorGen$.MissingArgsForMethodTpeError(ContextErrors.scala:682)
	scala.tools.nsc.typechecker.Typers$Typer.cantAdapt$1(Typers.scala:913)
	scala.tools.nsc.typechecker.Typers$Typer.instantiateToMethodType$1(Typers.scala:944)
	scala.tools.nsc.typechecker.Typers$Typer.adapt(Typers.scala:1225)
	scala.tools.nsc.typechecker.Typers$Typer.typed(Typers.scala:5794)
	scala.tools.nsc.typechecker.Typers$Typer.typedDefDef(Typers.scala:5996)
	scala.tools.nsc.typechecker.Typers$Typer.typed1(Typers.scala:5699)
	scala.tools.nsc.typechecker.Typers$Typer.typed(Typers.scala:5780)
	scala.tools.nsc.typechecker.Typers$Typer.typedStat$1(Typers.scala:5844)
	scala.tools.nsc.typechecker.Typers$Typer.$anonfun$typedStats$6(Typers.scala:3290)
	scala.tools.nsc.typechecker.Typers$Typer.$anonfun$typedStats$6$adapted(Typers.scala:3287)
	scala.Option$WithFilter.foreach(Option.scala:407)
	scala.tools.nsc.typechecker.Typers$Typer.$anonfun$typedStats$4(Typers.scala:3287)
	scala.tools.nsc.typechecker.Typers$Typer.$anonfun$typedStats$4$adapted(Typers.scala:3285)
	scala.reflect.internal.Scopes$Scope.foreach(Scopes.scala:435)
	scala.tools.nsc.typechecker.Typers$Typer.addSynthetics$1(Typers.scala:3285)
	scala.tools.nsc.typechecker.Typers$Typer.typedStats(Typers.scala:3349)
	scala.tools.nsc.typechecker.Typers$Typer.typedTemplate(Typers.scala:2019)
	scala.tools.nsc.typechecker.Typers$Typer.typedClassDef(Typers.scala:1832)
	scala.tools.nsc.typechecker.Typers$Typer.typed1(Typers.scala:5700)
	scala.tools.nsc.typechecker.Typers$Typer.typed(Typers.scala:5780)
	scala.tools.nsc.typechecker.Typers$Typer.typedStat$1(Typers.scala:5844)
	scala.tools.nsc.typechecker.Typers$Typer.$anonfun$typedStats$10(Typers.scala:3337)
	scala.tools.nsc.typechecker.Typers$Typer.typedStats(Typers.scala:3337)
	scala.tools.nsc.typechecker.Typers$Typer.typedBlock(Typers.scala:2497)
	scala.tools.nsc.typechecker.Typers$Typer.$anonfun$typed1$103(Typers.scala:5709)
	scala.tools.nsc.typechecker.Typers$Typer.typedOutsidePatternMode$1(Typers.scala:500)
	scala.tools.nsc.typechecker.Typers$Typer.typed1(Typers.scala:5744)
	scala.tools.nsc.typechecker.Typers$Typer.typed(Typers.scala:5780)
	scala.tools.nsc.typechecker.Typers$Typer.$anonfun$typedArg$1(Typers.scala:3355)
	scala.tools.nsc.typechecker.Typers$Typer.typedArg(Typers.scala:491)
	scala.tools.nsc.typechecker.Typers$Typer.typedArgToPoly$1(Typers.scala:3745)
	scala.tools.nsc.typechecker.Typers$Typer.$anonfun$doTypedApply$32(Typers.scala:3753)
	scala.tools.nsc.typechecker.Typers$Typer.handlePolymorphicCall$1(Typers.scala:3753)
	scala.tools.nsc.typechecker.Typers$Typer.doTypedApply(Typers.scala:3764)
	scala.tools.nsc.typechecker.Typers$Typer.normalTypedApply$1(Typers.scala:4909)
	scala.tools.nsc.typechecker.Typers$Typer.typedApply$1(Typers.scala:4918)
	scala.tools.nsc.typechecker.Typers$Typer.typed1(Typers.scala:5734)
	scala.tools.nsc.typechecker.Typers$Typer.typed(Typers.scala:5780)
	scala.tools.nsc.typechecker.Typers$Typer.computeType(Typers.scala:5855)
	scala.tools.nsc.typechecker.Namers$Namer.assignTypeToTree(Namers.scala:1114)
	scala.tools.nsc.typechecker.Namers$Namer.valDefSig(Namers.scala:1733)
	scala.tools.nsc.typechecker.Namers$Namer.memberSig(Namers.scala:1919)
	scala.tools.nsc.typechecker.Namers$Namer.typeSig(Namers.scala:1870)
	scala.tools.nsc.typechecker.Namers$Namer$ValTypeCompleter.completeImpl(Namers.scala:945)
	scala.tools.nsc.typechecker.Namers$LockingTypeCompleter.complete(Namers.scala:2081)
	scala.tools.nsc.typechecker.Namers$LockingTypeCompleter.complete$(Namers.scala:2079)
	scala.tools.nsc.typechecker.Namers$TypeCompleterBase.complete(Namers.scala:2074)
	scala.reflect.internal.Symbols$Symbol.completeInfo(Symbols.scala:1542)
	scala.reflect.internal.Symbols$Symbol.info(Symbols.scala:1514)
	scala.reflect.internal.Symbols$Symbol.initialize(Symbols.scala:1698)
	scala.tools.nsc.typechecker.Typers$Typer.typed1(Typers.scala:5403)
	scala.tools.nsc.typechecker.Typers$Typer.typed(Typers.scala:5780)
	scala.tools.nsc.typechecker.Typers$Typer.typedStat$1(Typers.scala:5844)
	scala.tools.nsc.typechecker.Typers$Typer.$anonfun$typedStats$10(Typers.scala:3337)
	scala.tools.nsc.typechecker.Typers$Typer.typedStats(Typers.scala:3337)
	scala.tools.nsc.typechecker.Typers$Typer.typedTemplate(Typers.scala:2019)
	scala.tools.nsc.typechecker.Typers$Typer.typedClassDef(Typers.scala:1832)
	scala.tools.nsc.typechecker.Typers$Typer.typed1(Typers.scala:5700)
	scala.tools.nsc.typechecker.Typers$Typer.typed(Typers.scala:5780)
	scala.tools.nsc.typechecker.Typers$Typer.typedStat$1(Typers.scala:5844)
	scala.tools.nsc.typechecker.Typers$Typer.$anonfun$typedStats$10(Typers.scala:3337)
	scala.tools.nsc.typechecker.Typers$Typer.typedStats(Typers.scala:3337)
	scala.tools.nsc.typechecker.Typers$Typer.typedPackageDef$1(Typers.scala:5410)
	scala.tools.nsc.typechecker.Typers$Typer.typed1(Typers.scala:5703)
	scala.tools.nsc.typechecker.Typers$Typer.typed(Typers.scala:5780)
	scala.tools.nsc.typechecker.Analyzer$typerFactory$TyperPhase.apply(Analyzer.scala:116)
	scala.tools.nsc.Global$GlobalPhase.applyPhase(Global.scala:453)
	scala.tools.nsc.interactive.Global$TyperRun.$anonfun$applyPhase$1(Global.scala:1340)
	scala.tools.nsc.interactive.Global$TyperRun.applyPhase(Global.scala:1340)
	scala.tools.nsc.interactive.Global$TyperRun.typeCheck(Global.scala:1333)
	scala.tools.nsc.interactive.Global.typeCheck(Global.scala:665)
	scala.meta.internal.pc.WithCompilationUnit.<init>(WithCompilationUnit.scala:22)
	scala.meta.internal.pc.SimpleCollector.<init>(PcCollector.scala:335)
	scala.meta.internal.pc.PcSemanticTokensProvider$Collector$.<init>(PcSemanticTokensProvider.scala:19)
	scala.meta.internal.pc.PcSemanticTokensProvider.Collector$lzycompute$1(PcSemanticTokensProvider.scala:19)
	scala.meta.internal.pc.PcSemanticTokensProvider.Collector(PcSemanticTokensProvider.scala:19)
	scala.meta.internal.pc.PcSemanticTokensProvider.provide(PcSemanticTokensProvider.scala:73)
	scala.meta.internal.pc.ScalaPresentationCompiler.$anonfun$semanticTokens$1(ScalaPresentationCompiler.scala:179)
```
#### Short summary: 

scala.ScalaReflectionException: value funct3 is not a method