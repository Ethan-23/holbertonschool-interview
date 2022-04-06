#!/usr/bin/node
const request = require('request');
async function main () {
  const myArgs = process.argv[2];
  const url = 'https://swapi-api.hbtn.io/api/films/' + myArgs;
  const json = JSON.parse(await doRequest(url));
  let i = 0;
  for (i in json.characters) {
    const chars = await doRequest(json.characters[i]);
    console.log(JSON.parse(chars).name);
  }
}

function doRequest (url) {
  return new Promise(function (resolve, reject) {
    request(url, function (error, res, body) {
      if (!error && res.statusCode === 200) {
        resolve(body);
      } else {
        reject(error);
      }
    });
  });
}

main();
