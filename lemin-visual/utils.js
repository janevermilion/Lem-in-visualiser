const restartButton = document.querySelector('#restart-button');
const scalePlus = document.querySelector('#scale-mapp');
const scaleMinus = document.querySelector('#scale-mapm');
const speedPlus = document.querySelector('#speedp');
const speedMinus = document.querySelector('#speedm');
const container = document.querySelector('.lemin-container');
const startButton = document.querySelector('#start-button');
const pauseButton = document.querySelector('#pause-button');
let roomSize = 40;
let screenWidth = window.screen.width;
let screenHeight = window.screen.height;
container.style.width = screenWidth;
container.style.height = screenHeight;
const widthOfGhost = Math.floor(roomSize / 1.5);
function returnMaxAndMinArrayValues(arr) {
    let resultArr = [];
    let xArr = [];
    let yArr = [];
    arr.forEach(function(room) {
        xArr.push(parseInt(room.x));
        yArr.push(parseInt(room.y));
    })
    let maxX = Math.max.apply(null, xArr);
    let maxY = Math.max.apply(null, yArr);
    let minX = Math.min.apply(null, xArr);
    let minY = Math.min.apply(null, yArr);
    resultArr.maxx = maxX;
    resultArr.maxy = maxY;
    resultArr.minx = minX;
    resultArr.miny = minY;
    return resultArr;
}

function is_overlap(arr) {
    let isOverlap = arr.some(function(room) {
        if (room['x'] * roomSize > screenWidth + roomSize)
            return true;
        else if (room['y'] * roomSize > screenHeight + roomSize)
            return true;
        else
            return false;
    })
    if (isOverlap === true) {
        let maxAndMinRoomValues = returnMaxAndMinArrayValues(arr);
        let bestScreenWidth = maxAndMinRoomValues.maxx * (roomSize + 2);
        let bestScreenHeight = maxAndMinRoomValues.maxy * (roomSize + 2);
        if (bestScreenWidth > screenWidth) {
            screenWidth = bestScreenWidth;
            container.style.width = screenWidth;
        }
        if (bestScreenHeight > screenHeight) {
            screenHeight = bestScreenHeight;
            container.style.height = screenHeight;
        }

    }
}

function is_too_big(arr) {

    let isOverlap = arr.some(function(room) {
        if (room['x'] * roomSize > screenWidth + roomSize)
            return true;
        else if (room['y'] * roomSize > screenHeight + roomSize)
            return true;
        else
            return false;
    })
    if (isOverlap === true) {
        let maxAndMinRoomValues;

        maxAndMinRoomValues = returnMaxAndMinArrayValues(arr);
        let maxX = maxAndMinRoomValues.maxx;
        let maxY = maxAndMinRoomValues.maxy;
        let delimY = 0;
        let delimX = 0;


        while (maxX > parseInt(screenWidth) / roomSize) {
            maxX /= 10;
            delimX++;
        }
        while (maxY > parseInt(screenHeight) / roomSize) {
            maxY /= 10;
            delimY++;
        }
        if (delimX > 1 || delimY > 1) {

            let maxDelim = delimX >= delimY ? delimX + 1 : delimY + 1;
            arr = arr.map(function(room) {
                room['x'] = Math.floor(parseInt(room['x']) / (maxDelim * 10));
                room['y'] = Math.floor(parseInt(room['y']) / (maxDelim * 10));
                return room;

            });
        }
    }
    return arr;
}

function changeInfo(info) {
    let maxAndMinRoomValues;

    maxAndMinRoomValues = returnMaxAndMinArrayValues(info['rooms']);
    info['rooms'] = info['rooms'].map(function(room) {
        room['x'] = Math.floor(parseInt(room['x']) - maxAndMinRoomValues.minx + 1);
        room['y'] = Math.floor(parseInt(room['y']) - maxAndMinRoomValues.miny + 1);
        return room;

    });

  //  info['rooms'] = is_too_big(info['rooms']);
    is_overlap(info['rooms']);
    return info;
}

function fillInfo(info) {
    let ants = document.getElementById('quant_ants');
    let roomList = document.getElementById('rooms-list');
    let roomsConnections = document.getElementById('rooms-connections');
    let antsPaths = document.getElementById('ants-paths');
    ants.innerText = 'Ants: ' + info['quant_of_ants'];

    let generatedRooms = info['rooms'].reduce(function(string, curr) {
        if (!string.length)
            return info['rooms'][0]['name'];
        return string + ', ' + curr['name']
    });
    roomList.innerText = 'Rooms: \n' + generatedRooms;
    let generatedConn = info['rooms'].reduce(function(string, curr) {
        if (!string.length) {
            let currConnections = info['rooms'][0]['connections'].reduce(function(connectionsString, currConn) {
                if (!connectionsString.length)
                    return curr['connections'][0];
                return connectionsString + ', ' + currConn;
            });
            return info['rooms'][0]['name'] + ': ' + currConnections + '\n'
        } else {
            if (curr['connections'].length) {
                let currConnections = curr['connections'].reduce(function(connectionsString, currConn) {
                    if (!connectionsString.length)
                        return curr['connections'][0];
                    return connectionsString + ', ' + currConn;
                });
                return string + (curr['name'] + ': ' + currConnections + '\n');
            } else
                return string + (curr['name'] + ': ' + 'no connections' + '\n');
        }

    })
    roomsConnections.innerText = 'Rooms connections:\n' + generatedConn;

    let generatedPaths = info['ants'].reduce(function(string, curr, index, array) {
        let firstString;
        if (!string.length) {
            firstString = 'L1: ' + info['ants'][0]['path'].reduce(function(connectionsString, currConn) {
                if (!connectionsString.length)
                    return info['ants'][0]['path'][0];
                if (!currConn)
                    return connectionsString;
                return connectionsString + '--> ' + currConn;
            }) + '\n';
        }
        let currConnections = curr['path'].reduce(function(connectionsString, currConn, index) {
            if (!connectionsString) {
                if (curr['path'][index])
                    return curr['path'][index];
                else
                    return connectionsString;
            }
            if (currConn) {
                if (connectionsString.length)
                    return connectionsString + '--> ' + currConn;
                else return currConn;
            } else
                return connectionsString
        });
        if (index === 1)
            return firstString + ('L' + curr['number'] + ': ' + currConnections + '\n');
        return string + ('L' + curr['number'] + ': ' + currConnections + '\n');
    })
    antsPaths.innerText = 'Ants paths:\n' + generatedPaths;

}
