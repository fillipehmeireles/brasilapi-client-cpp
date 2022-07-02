
# Brasil API HTTP Client

This project is a simple [Brasil API](https://brasilapi.com.br/) HTTP Client library built with C++.




## Lib Reference

#### Banks info
| Method | Params     |
| :-------- | :------- 
| `BrasilAPIProvider::getAllBanks`      | none | 
| `BrasilAPIProvider::getBankByCode`      | `string code` |

#### CEP info
| Method | Params     |
| :-------- | :------- 
| `BrasilAPIProvider::getCEPInfo`     | `char [9]` | 
| `BrasilAPIProvider::getCEPInfoV2`      | `char [9]` |

#### CNPJ info
| Method | Params     |
| :-------- | :------- 
| `BrasilAPIProvider::getCNPJInfo`     | `char [15]` | 

#### DDD info
| Method | Params     |
| :-------- | :------- 
| `BrasilAPIProvider::getDDDInfo`     | `char [3]` | 

#### Feriados Nacionais info
| Method | Params     |
| :-------- | :------- 
| `BrasilAPIProvider::getFeriadosNacionaisInfo`     | `char [5]` | 

#### FIPE info
| Method | Params     |
| :-------- | :------- 
| `BrasilAPIProvider::getFipeMarcasInfo`     | `string marca` | 
| `BrasilAPIProvider::getFipePrecoInfo`     | `string codigo_fipe` | 
| `BrasilAPIProvider::getFipeTabelasInfo`     | none | 

#### IBGE info
| Method | Params     |
| :-------- | :------- 
| `BrasilAPIProvider::getIBGEMunicipiosByUF`     | `char[3]` | 
| `BrasilAPIProvider::getIBGEAllStates`     | none | 
| `BrasilAPIProvider::getIBGEStateInfoByCode`     | `string code` | 


#### HTTPService::Response Struct
All Provider methods return `HTTPService::Response`.
```
  {
      long status_code; // HTTP Status Code
      std::string message // HTTP Response Message
  }
```

#### Utils
There's a extra utility to save the response to a JSON file.
```
  Utils::write_json_file (std::string filename, std::string json_buffer);
```
## Install & Run Example

```bash
  cd brasil-client-api
  cmake -S . -B build
  cmake --build build
  ./build/BrasilApiClient
```
