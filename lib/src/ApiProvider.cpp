#include "../include/ApiProvider.h"

BrasilAPIProvider::Provider::Provider() {
	this->http_service = std::make_unique<HTTPService::Service>(BRASIL_API_URL);
}

// Banks
HTTPService::Response BrasilAPIProvider::Provider::getAllBanks() {
	return this->http_service->requestData("GET", "/banks/v1");
}

HTTPService::Response BrasilAPIProvider::Provider::getBankByCode(std::string code) {
	return this->http_service->requestData("GET", "/banks/v1", code);
}

// CEP
HTTPService::Response BrasilAPIProvider::Provider::getCEPInfo(char CEP[CEP_BUFFER_SIZE]) {
	return this->http_service->requestData("GET", "/cep/v1", CEP);
}

HTTPService::Response BrasilAPIProvider::Provider::getCEPInfoV2(char CEP[CEP_BUFFER_SIZE]) {
	return this->http_service->requestData("GET", "/cep/v2", CEP);
}


// CNPJ
HTTPService::Response BrasilAPIProvider::Provider::getCNPJInfo(char CNPJ[CNPJ_BUFFER_SIZE]) {
	return this->http_service->requestData("GET", "/cnpj/v1", CNPJ);
}

// DDD
HTTPService::Response BrasilAPIProvider::Provider::getDDDInfo(char DDD[DDD_BUFFER_SIZE]) {
	return this->http_service->requestData("GET", "/ddd/v1", DDD);
}

// Feriados Nacionais
HTTPService::Response BrasilAPIProvider::Provider::getFeriadosNacionaisInfo(char ano[ANO_BUFFER_SIZE]) {
	return this->http_service->requestData("GET", "/feriados/v1", ano);
}

//  FIPE
HTTPService::Response BrasilAPIProvider::Provider::getFipeMarcasInfo(std::string marca) {
	return this->http_service->requestData("GET", "/fipe/marcas/v1", marca);
}

HTTPService::Response BrasilAPIProvider::Provider::getFipePrecoInfo(std::string codigo_fipe) {
	return this->http_service->requestData("GET", "/fipe/preco/v1", codigo_fipe);
}

HTTPService::Response BrasilAPIProvider::Provider::getFipeTabelasInfo() {
	return this->http_service->requestData("GET", "/fipe/tabelas/v1");
}

// IBGE
HTTPService::Response BrasilAPIProvider::Provider::getIBGEMunicipiosByUF(char sigla_UF[UF_BUFFER_SIZE]) {
	return this->http_service->requestData("GET", "/ibge/municipios/v1", sigla_UF);
}

HTTPService::Response BrasilAPIProvider::Provider::getIBGEAllStates() {
	return this->http_service->requestData("GET", "/ibge/uf/v1");
}

HTTPService::Response BrasilAPIProvider::Provider::getIBGEStateInfoByCode(std::string code) {
	return this->http_service->requestData("GET", "/ibge/uf/v1", code);
}
