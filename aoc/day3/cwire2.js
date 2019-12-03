var readline = require('readline');

var lreader = readline.createInterface({
    input: process.stdin,
});

const totalLines = 2;
var input = [], linesCount = 0;

lreader.on('line', function (inp) {
    input.push(inp);
    linesCount++;
    if(linesCount == totalLines) {
        main(input);
        lreader.close();
    }
});

function getCommand(input) {
    var cmd = input[0];
    var distance = parseInt(input.substring(1));
    return [cmd, distance];
}


function getCurrentPos(command, currentPos) {
    if(command == 'R') {
        return [currentPos[0]+1, currentPos[1]];
    }
    else if(command == 'L') {
        return [currentPos[0]-1, currentPos[1]];
    }
    else if(command == 'U') {
        return [currentPos[0], currentPos[1]+1];
    }
    else if(command == 'D') {
        return [currentPos[0], currentPos[1]-1];
    }
}

function main(args) {
    var firstWire = args[0].split(',');
    var secondWire = args[1].split(',');

    var grid = {};

    var currentPos = [0,0];
    var length=0;
    for(var J=0; J<firstWire.length; J++) {
        var cmd = getCommand(firstWire[J]);
        for(var I=1; I<=cmd[1]; I++) {
            currentPos = getCurrentPos(cmd[0], currentPos);
            length++;
            //add the current wire length to the grid
            grid[currentPos.toString()] = length;
        }
    }

    //Whole grid is populated;
    //check for the intersection
    currentPos = [0,0];
    result = [];
    length=0;
    for(var K=0; K<secondWire.length; K++) {
        var cmd = getCommand(secondWire[K]);
        for(var I=1; I<=cmd[1]; I++) {
            currentPos = getCurrentPos(cmd[0], currentPos);
            length++;
            if(grid[currentPos.toString()]) {
                //add the current wire length and the first wire length to result
                result.push(grid[currentPos.toString()]+length);
            };
        }
    }

    console.log("Intersection points: ", result.sort(function(a, b){return a - b}));

}
