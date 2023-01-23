#!/bin/bash

session="default-env"

tmux new-session -d -s $session

window=0
tmux split-window -t $window
tmux split-window -t $window
tmux select-layout -t $session even-horizontal

tmux attach-session -t $session
