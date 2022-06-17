#include <fstream>
#include "httplib.h"
#include <iostream>
using namespace httplib;
using namespace std;

const char *html = R"(
<form id="formElem">
  <input type="file" name="image_file" accept="image/*">
  <input type="file" name="text_file" accept="text/*">
  <input type="submit">
</form>
<script>
  formElem.onsubmit = async (e) => {
    e.preventDefault();
    let res = await fetch('/post', {
      method: 'POST',
      body: new FormData(formElem)
    });
    console.log(await res.text());
  };
</script>
)";

int main(void) {
  Server svr;

  svr.Get("/", [](const Request & /*req*/, Response &res) {
    res.set_content(html, "text/html");
  });
    
  svr.set_mount_point("/", "./");

  svr.Post("/post", [](const Request &req, Response &res) {
    auto file = req.get_file_value("file");

    ofstream ofs(file.filename, ios::binary);
    ofs << file.content;

    res.set_content("done", "text/plain");
  });

  svr.listen("0.0.0.0", 8020);
}
