#include <string>
#include <curl/curl.h>
#undef min
#undef max

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

static void request(std::string &readBuffer)
{
	static CURL *curl;
	static CURLcode res;

	readBuffer = "";

	curl = curl_easy_init();
	if (curl) 
	{
		curl_easy_setopt(curl, CURLOPT_URL, "http://task5.wbcdev.ru/api.bring?platform_id=2&need_bring=1&md5_gamename_plus_platform_id_hash=b68903245f98bcea98e0451e2e6bf8fe");
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}
}

static void Flag_request(std::string &readBuffer)
{
	static CURL *curl;
	static CURLcode res;

	readBuffer = "";

	curl = curl_easy_init();
	if (curl) 
	{
		curl_easy_setopt(curl, CURLOPT_URL, "http://task5.wbcdev.ru/api.getflag?hash=9bef9c3a6419c45b1a3bc482f33fce8f");
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}
}