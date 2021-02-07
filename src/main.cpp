#include <httplib.h>

int main()
{
    using namespace httplib;

    Server svr;

    svr.Get(R"(/api/(.+))", [&](const Request &req, Response &res) {
        std::string api = req.matches[1];
        if (api == "echo" ) {
            std::string message = req.get_param_value("message");
            res.set_content(R"({"data":{"message":")"+ message + R"("},"status":"OK"})","application/json");
            std::cout << R"({"data":{"message":")"+ message + R"("},"status":"OK"}\n)" << "\n";
        } else {
            res.set_content(R"({"data":{},"status":"BAD_REQUEST"})","application/json");
            std::cout << "BAD_REQUEST";
        }
    });

    svr.set_base_dir("./web/");

    svr.listen("localhost", 8088);
}
