# aliasprint
Windows Utility to Redirect stdin to a UNC printer path

## this is a workaround for BBj 

java.nio.Paths that adds an extra backslash also to UNC printer paths:

>name$ = "\\192.168.0.13\printer"
>p! = java.nio.file.Paths.get(name$)
>? p!
\\192.168.0.13\printer\
>f! = new java.io.File(name$)
>path! = f!.toPath()
>? path!
\\192.168.0.13\printer\


As a result OPENing a printer that is configured with UNC fails. 

## how it works

this utility reads from stdin and outputs this data to the device that is passed as the first argument. 

NOTE: there is no additional checking provided to verify that the parameter is indeed a printer share. 

## refernce

Bug 30087 - Error=3 when printing to an ALIAS that points to an UNC path is broken - BBj internally adds / making the path invalid [https://bugzilla.basis.com/show_bug.cgi?id=30087]

