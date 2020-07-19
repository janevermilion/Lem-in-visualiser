module.exports.parseInfo = function(text)
{
    // let splitted_info = text.split('\r\n');//for Win
    let splitted_info = text.split('\n');
    if (splitted_info[0] === 'ERROR')
        throw new Error('File is not valid.\nError description: ' + splitted_info[1]);
    else if (splitted_info[0] === '<!DOCTYPE html>')
        throw new Error('File not found');
    let Indexes =findMainIndexes(splitted_info);
    let info = [];
    info['quant_of_ants'] = splitted_info[0];
    let Rooms = [];
    for(var i = 1;i < Indexes['paths'];i++)
    {
        if(i!==Indexes['start'] -1 && i !== Indexes['end'] - 1)
        {
            let opt = null;
            if(i === Indexes['start'])
                opt ="start";
            else if(i === Indexes['end'])
                opt = "end";
            let r = new Room(splitted_info[i], opt);
            if ((r['name'][0] === '#' && opt) || r['name'][0] !== '#')
                Rooms.push(r);
        }

    }
    info['rooms'] = Rooms;
    createConnections(splitted_info, info['rooms'],Indexes);
    let ants = [];
    for(var i =1; i<= parseInt(info['quant_of_ants']);i++)
    {
        ants.push(new Ant(i, splitted_info.slice(Indexes['solution'], splitted_info.length - 1)));
    }
    info['ants'] = ants;
    return info
   // draw(info);
}