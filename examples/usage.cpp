#include <iostream>

#include "ApiProvider.h"
#include "HTTPService.h"
#include "Utils.h"

#include <nlohmann/json.hpp>

std::ostream& operator<< (std::ostream& out, HTTPService::Response response)
{
	out << std::setw(4) << nlohmann::json::parse(response.message) <<  "\n";
	return out;
}

#define CNPJ_BUFFER_SIZE 15
#define CEP_BUFFER_SIZE 9
#define DDD_BUFFER_SIZE 3
#define ANO_BUFFER_SIZE 5
#define UF_BUFFER_SIZE 3

int main(int argc, char ** argv)
{
	setlocale(LC_ALL, "pt_BR.UTF-8");

	

	std::unique_ptr<BrasilAPIProvider::Provider> brasil_api_provider = std::make_unique<BrasilAPIProvider::Provider>();
	BrasilAPIProvider::Provider brasil_provider_api;
	HTTPService::Service http_service = HTTPService::Service(BRASIL_API_URL);

	char CNPJ[CNPJ_BUFFER_SIZE] = "00000000000191";
	char CEP[CEP_BUFFER_SIZE] = "45880000";
	char DDD[DDD_BUFFER_SIZE] = "73";
	char ano[ANO_BUFFER_SIZE] = "2022";
	char sigla_UF[UF_BUFFER_SIZE] = "BA";


	std::string bank_code = "00000000";
	std::string marca = "motos";
	std::string codigo_fipe = "021330-6";
	std::string state_code = sigla_UF;

	HTTPService::Response all_banks = brasil_api_provider->getAllBanks(); // All Banks
	HTTPService::Response bank_by_code = brasil_api_provider->getBankByCode(bank_code); // Bank by code
	
	HTTPService::Response cep_info = brasil_api_provider->getCEPInfo(CEP); // Cep Info
	HTTPService::Response cep_info_v2 = brasil_api_provider->getCEPInfoV2(CEP); // Cep Info V2
	
	HTTPService::Response cnpj_info = brasil_api_provider->getCNPJInfo(CNPJ); // CNPJ Info
	HTTPService::Response ddd_info = brasil_api_provider->getDDDInfo(DDD); // DDD Info
	HTTPService::Response feriados_nacionais_info = brasil_api_provider->getFeriadosNacionaisInfo(ano); // Feriados Nacionais
	
	// FIPE
	HTTPService::Response fipe_marcas_info = brasil_api_provider->getFipeMarcasInfo(marca);
	HTTPService::Response fipe_preco_info = brasil_api_provider->getFipePrecoInfo(codigo_fipe);
	HTTPService::Response fipe_tabelas_info = brasil_api_provider->getFipeTabelasInfo();
	
	// IBGE
	HTTPService::Response ibge_municipios_info = brasil_api_provider->getIBGEMunicipiosByUF(sigla_UF);
	HTTPService::Response ibge_all_states_info = brasil_api_provider->getIBGEAllStates();
	HTTPService::Response ibge_state_info = brasil_api_provider->getIBGEStateInfoByCode(state_code);

    std::cout << cep_info;

	Utils::write_json_file("cep_info", cep_info.message); // Saving response to a file

    return EXIT_SUCCESS;
   
}
