#include <wrl/module.h>

using namespace Microsoft::WRL;

#if !defined(__WRL_CLASSIC_COM__)
extern "C" HRESULT __stdcall DllGetActivationFactory(_In_ HSTRING activatibleClassId, _COM_Outptr_ IActivationFactory** factory)
{
    return Module<InProc>::GetModule().GetActivationFactory(activatibleClassId, factory);
}
#endif

#if !defined(__WRL_WINRT_STRICT__)
extern "C" HRESULT __stdcall DllGetClassObject(REFCLSID rclsid, REFIID riid, _COM_Outptr_ void** ppv)
{
    return Module<InProc>::GetModule().GetClassObject(rclsid, riid, ppv);
}
#endif

extern "C" HRESULT __stdcall DllCanUnloadNow()
{
    return Module<InProc>::GetModule().Terminate() ? S_OK : S_FALSE;
}

extern "C" BOOL __stdcall DllMain( _In_opt_ HINSTANCE hinst, DWORD reason, void** ppv)
{
    if (reason == DLL_PROCESS_ATTACH)
    {
        DisableThreadLibraryCalls(hinst);
    }
    return TRUE;
}

