var connect = require('connect');
var serveStatic = require('serve-static');
const fetch = require("node-fetch");///del&
var fs = require('fs');
const jsdom = require("jsdom");
const { JSDOM } = jsdom;

const getData = (fileName, type) =>
    new Promise((resolve, reject) =>
        fs.readFile(fileName, type, (err, data) => {
            //if has error reject, otherwise resolve
            return err ? reject(err) : resolve(data);
        })
    );


const parseModule= require(__dirname + '/parseInfo.js');
const drawModule = require(__dirname + '/drawParsed.js')
getData(process.argv[2], 'utf8')
    .then(text =>
    {
        return parseModule.parseInfo(text);
    })
    .then(data => {
        console.log('Data: ', data)
        connect()
            .use(serveStatic(__dirname))
            .listen(8000, () => {console.log('Visualiser running on http://localhost:8000')
            });
       // drawModule.draw(data);
    })
    .catch(error => console.log('Error: ', error));
/*
(async () => {
    await fetch('result.txt')
        .then(res=>{console.log(res)})

        .then(function (response) {
            return response.text();
        })
        .then(function (text) {
            parseInfo(text);
        })
        .catch(function (error) {
            console.log(error);
            let errorHeader = document.createElement("h1");
            errorHeader.classList.add('error-header');
            errorHeader.innerText = error;
            if (error.toString() === "TypeError: Failed to fetch")
                errorHeader.innerText = error.toString() + '\nPlease, start the web-server.'
            if (error.toString() === "TypeError: Reduce of empty array with no initial value")
                errorHeader.innerText = 'File to parse is not found.'
            container.append(errorHeader);
            document.querySelector('.info_about').style.display = 'none';
            document.querySelector('.buttons-container').style.display = 'none';
        })
})();*/
/*
connect()
    .use(serveStatic(__dirname))
    .listen(8000, () => {console.log('Visualiser running on http://localhost:8000')
    });*/
