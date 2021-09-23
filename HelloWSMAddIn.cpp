#include "pch.h"

// If you get this error compiling the solution.
// C:\Git\HelloWSMAddIn\HelloWSMAddIn.cpp(12, 1) : fatal error C1189 : #error:  "FormItSupport directory not found. Download it from <>"// You did not follow the step to copy the FormItSupport directory
// to the HelloWSMAddIn directory. You can find the FormItSupport.zip directory in the
// 'FormItSDK_{$SDKVersion}.zip' file on the ADN web site for FormIt.

#if __has_include("FormItSupport/WSMScripting/IScriptInstance.h")
#include "FormItSupport/WSMScripting/IScriptInstance.h"
#else
#error "FormItSupport directory not found. Download it from FormIt ADN site"
#endif

#include "JournalingSupport/JournalVariable.h"

#include "FormItCore/include/FormItCoreAPIDLL.h"

#include <sstream>

REGISTERAPIMETHODS
{
    if (!scriptInstance)
        return;

    // Example to call JS code
    scriptInstance->Evaluate("console.log(\"Registering HelloWSMDLL JS functions from HelloWSMDLL!!!\")");

    // Add new JS APIs
    REGISTERNAMESPACE("HelloWSMAddIn")

    APIMETHOD(HelloWSMAddIn, CreateBlock, "nHistoryID, pt1, pt2")
    {
        SCRIPTCONVERTER(size_t, nHistoryID);
        SCRIPTCONVERTER(WSM::Point3d, pt1);
        SCRIPTCONVERTER(WSM::Point3d, pt2);

        size_t blockID = WSM::INVALID_ID;

        WSM::APICreateBlock(nHistoryID, pt1, pt2, blockID);
        return to_json(blockID);
    });

    REGISTERNAMESPACE("HelloWSMDLL.WSMUtils")

    APIMETHOD(HelloWSMAddIn.WSMUtils, GetWorldBounds, "")
    {
        WSM::Utils::IAppHelper *appHelper = WSM::Utils::GetAppHelper();

        if (appHelper)
        {
            return to_json(appHelper->GetWorldBounds());
        }

        return JSON_UNDEFINED;
    });

}
