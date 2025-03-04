#include "data.hpp"
#include "symbol.hpp"
#include "common.hpp"

extern void DataRegisterFunc(Symbol, DataNode (*)(DataArray *));
extern bool OptionBool(const char*, bool);
extern char* OptionStr(const char*, const char*);

DataNode DataOptionStr(DataArray* da){
	char* str = OptionStr(da->GetStrAtIndex(1), nullptr);
	if(str != nullptr){
		da->GetVarAtIndex(2)->operator=(DataNode(str));
		return DataNode(1);
	}
	else return DataNode(0);
}

DataNode DataOptionSym(DataArray* da){
	char* str = OptionStr(da->GetStrAtIndex(1), nullptr);
	Symbol s(str);
	if(s.IsNull()){
		return DataNode(0);
	}
	else {
		da->GetVarAtIndex(2)->operator=(DataNode(s));
		return DataNode(1);
	}
}

DataNode DataOptionBool(DataArray* da){
	return DataNode(OptionBool(da->GetStrAtIndex(1), false));
}

void OptionInit(){
	DataRegisterFunc("option_bool", DataOptionBool);
	DataRegisterFunc("option_str", DataOptionStr);
	DataRegisterFunc("option_sym", DataOptionSym);
}

char* UnknownLLX(){
	return "%llx";
}