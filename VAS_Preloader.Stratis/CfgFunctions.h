class CfgFunctions
{
	class VAS
	{
		tag = "VAS";
		
		class Functions
		{
			class configBuilder {file = "fn_configBuilder.sqf"};
			class fetchCfgDetails {file = "fn_fetchCfgDetails.sqf"};
			class KRON_StrLeft {file = "fn_KRON_StrLeft.sqf"};
			class KRON_StrToArray {file = "fn_KRON_StrToArray.sqf"};
			class initBuilder {file = "fn_initBuilder.sqf"; postInit = 1;};
		};
	};
};