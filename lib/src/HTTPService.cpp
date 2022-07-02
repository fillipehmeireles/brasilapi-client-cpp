#include "../include/HTTPService.h"

HTTPService::Response HTTPService::Service::GET()
{
	cpr::Response resp = cpr::Get(cpr::Url{ this->URL });
	
	return Response{ resp.status_code,resp.text };
}
HTTPService::Response  HTTPService::Service::requestData(std::string HTTPMethod, std::string endpoint, std::optional<std::string>payload)
{
	this->URL = this->baseURL;
	if(payload.has_value())
		this->URL = this->URL + endpoint + "/" + payload.value();
	return (this->*actions.find(HTTPMethod)->second)();
}

