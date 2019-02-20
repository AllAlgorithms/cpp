/**
 * The All Algorithms C++ Validate.js
 * 
 * Author: Carlos Abraham Hernandez
 * https://abranhe.com (abraham@abranhe.com)
 */
'use strict';

const glob = require('glob');
const path = require('path');
const decamelize = require('decamelize');
const shell = require('child_process').execSync;

const getFiles = (src, callback) => {
  glob(src + '/**', callback);
};

getFiles('../', (err, res) => {
  if (err) {
    console.log('Error', err);
  } else {
    res.map((file) => {
      // Accept only valid C++ Files (.cpp,.hpp,.h)
      if (path.extname(file) !== '.cpp' && path.extname(file) !== '.hpp' && path.extname(file) !== '.h') {
        return;
      }

      if(file !== decamelize(file)){
        console.log('Don\'t follow the All ▲lgorithms structure. :/');
        process.exit();
      }      
    });
  }
});