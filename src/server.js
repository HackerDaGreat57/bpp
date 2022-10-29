var zlib = require('zlib');
var http = require('http');
var fs = require('fs');

console.log("Creating HTTP server.");

http.createServer(function(request, response) {
  var response_data = fs.createReadStream(request.url);
  if(response_data = '/') {
    response_data = 'index.html';
  }
  var acceptEncoding = request.headers['accept-encoding'];
  if (!acceptEncoding) {
    acceptEncoding = '';
  }
	
	console.log(response_data);

  if (acceptEncoding.match("gzip")) {
    console.log("gzip");
		response.writeHead(200, {'content-encoding': 'gzip'});
    response_data.pipe(zlib.createGzip()).pipe(response);
	} else if (acceptEncoding.match("deflate")) {
    console.log("deflate");
		response.writeHead(200, {'content-encoding': 'deflate'});
    response_data.pipe(zlib.createDeflate()).pipe(response);
  } else {
    console.log("regular");
    response.writeHead(200, {});
    response_data.pipe(response);
  }
}).listen(3726);
console.log("Finished creating HTTP server.");