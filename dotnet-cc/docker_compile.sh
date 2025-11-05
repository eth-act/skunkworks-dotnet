#!/bin/bash

set -xe

mkdir -p mod_export
mkdir -p out

docker run -v $(pwd):/build --rm dotnet2c /zkvm/cc.sh
