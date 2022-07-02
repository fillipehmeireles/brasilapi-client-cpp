#pragma once

#include <string>
#include <map>
#include <optional>
#include <cpr/cpr.h>

namespace HTTPService 
{
	struct Response
	{
		long status_code;
		std::string message;
	};


	class Service
	{
	private:
		std::string baseURL;
		std::string URL;
		typedef Response(HTTPService::Service::* callback)();
		std::map<std::string, callback> actions;
		Response GET();
	public:
		
		Service(std::string baseURL):actions{{"GET", &HTTPService::Service::GET}} {
			this->baseURL = baseURL;
		};
		Response requestData(std::string HTTPMethod, std::string endpoint, std::optional< std::string> payload = std::nullopt);
	};
}