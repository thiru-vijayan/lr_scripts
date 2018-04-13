/* 	Script Name: 
 	Application: 
 	Function: 
 	Date: 2018/04/13
 	Author: Hitachi/Thiru Vijayan	*/

HttpBin()
{

// Request 1 - 
	strTransName = lr_eval_string("01_httpbin_GET");
	lr_start_transaction(strTransName);
	
	web_add_header("Accept", "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8");
	web_add_header("Accept-Encoding", "gzip, deflate");
	web_add_header("Accept-Language", "en-US,en;q=0.9");
	web_add_header("Connection", "close");
	web_add_header("Host", "httpbin.org");
	web_add_header("Upgrade-Insecure-Requests", "1");
	web_add_header("Accept-Encoding", "gzip, deflate");
	
	web_custom_request("LaunchHomePage",
	    "URL={P_protocol}://{P_URL}/get",
	    "Method=GET",
	    LAST);
	
	HTTP_RETURN_CODE = web_get_int_property(HTTP_INFO_RETURN_CODE);
    
    if (HTTP_RETURN_CODE == 200)
    {
    	lr_end_transaction(strTransName, LR_PASS);
    }
    else
    {
    	lr_end_transaction(strTransName, LR_FAIL);	
    }
    
	return 0;
}
