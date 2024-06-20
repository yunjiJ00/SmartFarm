#!/bin/bash

echo "start"

mysql -u root -p << EOF

use team1
select * from dht;

EOF

echo "end"
