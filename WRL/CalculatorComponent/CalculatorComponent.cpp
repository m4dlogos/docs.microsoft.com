#include "CalculatorComponent_h.h"
#include <wrl.h>

using namespace Microsoft::WRL;

class CalculatorComponent : public RuntimeClass<RuntimeClassFlags<ClassicCom>, ICalculatorComponent>
{
public:
	CalculatorComponent() {}

	HRESULT __stdcall Add(_In_ int a, _In_ int b, _Out_ int* value)
	{
		*value = a + b;
		return S_OK;
	}
};

CoCreatableClass(CalculatorComponent);