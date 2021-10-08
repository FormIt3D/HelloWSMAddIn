WSM Addin example creating user defined JS commands using WSM C++ APIs.
========================

![Main Preview](preview.png)

This is an example of the [FormIt Modeling Kernel API](https://formit3d.github.io/FormItExamplePlugins/docs/FormItCPPAPI/group__mod__wsm__api__ref.html).
To load this plugin, run this in the FormIt console-
```
FormIt.LoadPlugin("https://formit3d.github.io/HelloWSMAddIn");
```

1) Download the FormItSupport directory from the ADN web site
2) Unzip the FormItSupport directory into the DLL
3) Build the DLL
4) Use the following commands to call the new JS APIs in the DLL
```
var pt1 = WSM.Geom.Point3d(0,0,0);
var pt2 = WSM.Geom.Point3d(10,10,10);
HelloWSMAddIn.CreateBlock(0, pt1, pt2);
var bounds = HelloWSMAddIn.WSMUtils.GetWorldBounds();
console.log(bounds);
```
