#pragma once

#include "HTTPService.h"
#include "Globals.h"
#include <memory>
namespace BrasilAPIProvider {

	class Provider
	{
	private:
		std::unique_ptr<HTTPService::Service> http_service;
	public:
		Provider();
		HTTPService::Response getAllBanks(); // All Banks
		HTTPService::Response getBankByCode(std::string code); // Bank by code
		HTTPService::Response getCEPInfo(char CEP[CEP_BUFFER_SIZE]); // CEP Info
		HTTPService::Response getCEPInfoV2(char CEP[CEP_BUFFER_SIZE]); // CEP Info V2
		HTTPService::Response getCNPJInfo(char CNPJ[CNPJ_BUFFER_SIZE]); // CNPJ Info
		HTTPService::Response getDDDInfo(char DDD[DDD_BUFFER_SIZE]); // DDD Info
		HTTPService::Response getFeriadosNacionaisInfo(char ano[ANO_BUFFER_SIZE]); // Feriados Nacionais 

		// FIPE
		HTTPService::Response getFipeMarcasInfo(std::string marca);
		HTTPService::Response getFipePrecoInfo(std::string codigo_fipe);
		HTTPService::Response getFipeTabelasInfo();

		//IBGE
		HTTPService::Response getIBGEMunicipiosByUF(char sigla_UF[UF_BUFFER_SIZE]);
		HTTPService::Response getIBGEAllStates();
		HTTPService::Response getIBGEStateInfoByCode(std::string code);

	};
}
