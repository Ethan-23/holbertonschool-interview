#!/usr/bin/node
const myArgs = process.argv[2];
const request = require('request');
const url = 'https://swapi-api.hbtn.io/api/films/' + myArgs;
request(url, (error, response, body) => {
  if (error) console.log(error);
  const json = JSON.parse(body);
  let i = 0;
  for (i in json.characters) {
    getCharacter(json.characters[i]);
  }
});

async function getCharacter (url) {
  await request(url, (error, response, body) => {
    if (error) console.log(error);
    console.log(JSON.parse(body).name);
  });
}
