/**
 * validate.js
 * 
 * The All ▲lgorithms validator CLI
 * 
 * Author: Carlos Abraham Hernandez
 * https://abranhe.com (abraham@abranhe.com)
 */
'use strict';

const glob = require('glob');
const path = require('path');
const decamelize = require('decamelize');
const chalk = require('chalk');
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

      if (file !== decamelize(file)) {
        console.log(`The file ${chalk.red(path.basename(file))} does not follow the correct style.`);
        // Stop when a file with wrong format is found
        throw new TypeError(`File project style does not follow the All ▲lgorithms structure.`);
      }
      console.log(`The file ${chalk.green(path.basename(file))} is ok.`);
    });
  }
});
