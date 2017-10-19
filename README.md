# aliasprint
Windows Utility to Redirect stdin to a UNC printer path

## this is a workaround for BBj 

java.nio.Paths that adds an extra backslash also to UNC printer paths:


```
>name$ = "\\192.168.0.13\printer"
>p! = java.nio.file.Paths.get(name$)
>? p!
\\192.168.0.13\printer\
>f! = new java.io.File(name$)
>path! = f!.toPath()
>? path!
\\192.168.0.13\printer\
```

As a result OPENing a printer that is configured with UNC fails. 

## how it works

this utility reads from stdin and outputs this data to the device that is passed as the first argument. 

NOTE: there is no additional checking provided to verify that the parameter is indeed a printer share. 

## refernce

Bug 30087 - Error=3 when printing to an ALIAS that points to an UNC path is broken - BBj internally adds / making the path invalid [https://bugzilla.basis.com/show_bug.cgi?id=30087]

##instructions from the bug report:

Turns out that this is a particular behavior of java nio Paths on Windows UNC printer paths. For the time being, I can offer the following workaround that might work in most deployment scenarios:

- clone https://github.com/BasisHub/aliasprint or get the aliasprint.exe directly from 

https://github.com/BasisHub/aliasprint/blob/master/bin/aliasprint.exe?raw=true

- put it on the Windows server that needs to print to the UNC printer paths

- structure your alias like this:

```
ALIAS P1 ">D:/path/to/aliasprint.exe //server/printershare" "" CR
```

Then you should be able to 

```
OPEN (7)"P1"
PRINT (7)"test"
CLOSE (7)
```
