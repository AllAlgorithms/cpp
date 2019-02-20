/**
 * The All Algorithms C++ Formatter
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

      // Only avilable for Linux/Macos
      // https://stackoverflow.com/a/41030518/7602110
      // Can be replaced in the future
      shell(`mv ${file} ${decamelize(file)}`);

      // Replace for convention .h for .hpp
      if (path.extname(file) === '.h') {
        shell(`mv ${file} ${file.replace(/\.[^\.]+$/, '.hpp')}`);
      }
    });
  }
});
