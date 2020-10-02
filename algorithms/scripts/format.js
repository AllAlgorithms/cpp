#!/usr/bin/env node
'use strict';

/**
 * Usage: node format.js
 *
 * Author: Carlos Abraham Hernandez
 * https://abranhe.com (abraham@abranhe.com)
 */

const path = require('path');
const glob = require('glob');
const chalk = require('chalk');
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
      shell(`mv ${file.replace(' ', '\\ ')} ${decamelize(file.replace(' ', '_'))}`);

      if (file.replace(' ', '\\ ') !== decamelize(file)) {
        console.log(
          `The file ${chalk.red(file)} was successfuly changed to ${chalk.green(decamelize(file.replace(' ', '_')))}`
        );

        // Change file on git history
        // https://stackoverflow.com/a/16071375/7602110
        shell(`cd ../\
        git mv --force ${file.replace(' ', '\\ ').replace('../', '')} ${decamelize(
          file.replace(' ', '_').replace('../', '')
        )}`);
      }

      // Replace for convention .h for .hpp
      if (path.extname(file) === '.h') {
        shell(`mv ${file} ${file.replace(/\.[^\.]+$/, '.hpp')}`);
      }
    });
  }
});
