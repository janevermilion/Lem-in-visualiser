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

getData(process.argv[2], 'utf8')
    .then(text =>
    {
        var result = "let fileName = \'" + process.argv[2] + "\';";
        try{
            fs.writeFileSync('filename.js', result);
        }catch (e){
            console.log("Cannot write file ", e);
        }
        console.log('THE MAP IS:\n' + text);
        connect()
            .use(serveStatic(__dirname))
            .listen(8000, () => {console.log('Visualiser running on http://localhost:8000')
            });
    })
    .catch(error => console.log('Error: ', error));
