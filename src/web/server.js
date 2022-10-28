var zlib = require('zlib');
var http = require('http');
var fs = require('fs');

console.log("Creating HTTP server.");

http.createServer(function(request, response) {
  var raw = fs.createReadStream('index.js');
  var acceptEncoding = request.headers['accept-encoding'];
  if (!acceptEncoding) {
    acceptEncoding = '';
  }
	
	console.log("Working on setting up compression...");

  if (acceptEncoding.match("br")) {
    console.log("br");
		response.writeHead(200, {'content-encoding': 'brotli'});
    raw.pipe(zlib.createBrotliCompress()).pipe(response);
  } else if (acceptEncoding.match("gzip")) {
    console.log("gzip");
		response.writeHead(200, {'content-encoding': 'gzip'});
    raw.pipe(zlib.createGzip()).pipe(response);
	} else if (acceptEncoding.match("deflate")) {
    console.log("deflate");
		response.writeHead(200, {'content-encoding': 'deflate'});
    raw.pipe(zlib.createDeflate()).pipe(response);
  } else {
    console.log("regular");
    response.writeHead(200, {});
    raw.pipe(response);
  }
}).listen(3726);
console.log("Finished creating HTTP server.");