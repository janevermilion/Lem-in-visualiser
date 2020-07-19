var connect = require('connect');
var serveStatic = require('serve-static');

connect()
    .use(serveStatic(__dirname))
    .listen(8000, () => {console.log('Visualiser running on http://localhost:8000')
    });