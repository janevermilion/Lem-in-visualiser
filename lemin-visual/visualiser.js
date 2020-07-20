var connect = require('connect');
var serveStatic = require('serve-static');
var fs = require('fs');

const getData = (fileName, type) =>
    new Promise((resolve, reject) =>
        fs.readFile(fileName, type, (err, data) => {
            //if has error reject, otherwise resolve
            return err ? reject(err) : resolve(data);
        })
    );

getData('result.txt', 'utf8')
    .then(text =>
    {
        connect()
            .use(serveStatic(__dirname))
            .listen(8888, () => {console.log('Visualiser running on http://localhost:8888')
            });
    })
    .catch(error => console.log('Error: ', error));
