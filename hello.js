var http = require('http');
http.createServer(function (req, res) 
{
    res.writeHead(200, {'Content-Type' : 'text/plain'});
    res.end('TAHA WAS HERE !');
}).listen(8080);
