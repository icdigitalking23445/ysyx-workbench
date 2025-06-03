ThisBuild / scalaVersion := "2.12.13"

val chiselVersion = "3.5.3"

lazy val root = (project in file("."))
  .settings(
    name := "chisel-npc",
    libraryDependencies ++= Seq(
      "edu.berkeley.cs" %% "chisel3"    % chiselVersion,
      "edu.berkeley.cs" %% "chiseltest" % "0.5.3" % "test",
      "org.scalatest"    %% "scalatest" % "3.2.16" % "test"
    ),
    addCompilerPlugin("edu.berkeley.cs" % "chisel3-plugin" % chiselVersion cross CrossVersion.full),
    scalacOptions ++= Seq(
      "-deprecation",
      "-feature",
      "-unchecked",
      "-Xfatal-warnings",
      "-language:reflectiveCalls"
    )
  )

