var zlib = require('zlib');
var http = require('http');
var fs = require('fs');

console.log("Creating HTTP server.");

http.createServer(function(request, response) {
  var index_html = fs.createReadStream('index.html');
  var index_js = fs.createReadStream('index.js');
  var index_css = fs.createReadStream('index.css');
  var acceptEncoding = request.headers['accept-encoding'];
  if (!acceptEncoding) {
    acceptEncoding = '';
  }
	
	console.log("Working on setting up compression...");

  if (acceptEncoding.match("br")) {
    console.log("br");
		response.writeHead(200, {'content-encoding': 'brotli'});
    index_html.pipe(zlib.createBrotliCompress()).pipe(response);
    index_css.pipe(zlib.createBrotliCompress()).pipe(response);
    index_js.pipe(zlib.createBrotliCompress()).pipe(response);
  } else if (acceptEncoding.match("gzip")) {
    console.log("gzip");
		response.writeHead(200, {'content-encoding': 'gzip'});
    index_html.pipe(zlib.createGzip()).pipe(response);
    index_css.pipe(zlib.createGzip()).pipe(response);
    index_js.pipe(zlib.createGzip()).pipe(response);
	} else if (acceptEncoding.match("deflate")) {
    console.log("deflate");
		response.writeHead(200, {'content-encoding': 'deflate'});
    index_html.pipe(zlib.createDeflate()).pipe(response);
    index_css.pipe(zlib.createDeflate()).pipe(response);
    index_js.pipe(zlib.createDeflate()).pipe(response);
  } else {
    console.log("regular");
    response.writeHead(200, {});
    index_html.pipe(response);
    index_css.pipe(response);
    index_js.pipe(response);
  }
}).listen(3726);
console.log("Finished creating HTTP server.");