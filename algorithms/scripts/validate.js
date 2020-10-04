#!/usr/bin/env node
'use strict';

/**
 * The All ▲lgorithms validator CLI
 * 
 * Usage: node validate.js
 * 
 * Author: Carlos Abraham Hernandez
 * https://abranhe.com (abraham@abranhe.com)
 */

const glob = require('glob');
const path = require('path');
const decamelize = require('decamelize');
const chalk = require('chalk');

const getFiles = (src, callback) => {
  glob(src + '/**', callback);
};

getFiles('../', (err, res) => {
  if (err) {
    console.log('Error', err);
  } else {
    let invalid = false;
    res.map((file) => {
      // Accept only valid C++ Files (.cpp,.hpp,.h)
      if (path.extname(file) !== '.cpp' && path.extname(file) !== '.hpp' && path.extname(file) !== '.h') {
        return;
      }

      if (file !== decamelize(file.replace(' ', ''))) {
        console.log(`${chalk.red(path.basename(file))} does not follow the correct style.`);
        let invalid = true;
      }
      console.log(`${chalk.green(path.basename(file))} is ok.`);
    });
    if (invalid) {
      // Throw an error at the end of checking all files
      throw new TypeError(`Expected the All ▲lgorithms structure.`);
    }
  }
});
