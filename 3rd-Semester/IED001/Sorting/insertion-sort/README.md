# Insertion Sort

## Original List
$${7 \rightarrow 15 \rightarrow 3 \rightarrow 1}$$

## Iterations
$${1st: \quad \color{blue} 7 \color{gray} \rightarrow 15 \rightarrow 3 \rightarrow 1}$$

$${2nd: \quad \color{gray} 7 \rightarrow \color{blue} 15 \color{gray} \rightarrow 3 \rightarrow 1}$$

$${3rd: \quad \color{yellow} 7 \color{gray} \rightarrow \color{yellow} 15 \color{gray} \rightarrow 3 \rightarrow 1}$$

$${4th: \quad \color{gray} 7 \rightarrow 15 \rightarrow  \color{blue} 3 \color{gray} \rightarrow 1}$$

$${5th: \quad \color{gray} 7 \rightarrow \color{yellow} 15 \color{gray} \rightarrow  \color{yellow} 3 \color{gray} \rightarrow 1}$$

$${6th: \quad \color{yellow} 7 \color{gray} \rightarrow \color{yellow} 3 \color{gray} \rightarrow 15 \rightarrow 1}$$

$${7th: \quad \color{gray} 3 \rightarrow 7 \rightarrow 15 \rightarrow \color{blue} 1 \color{gray}}$$

$${8th: \quad \color{gray} 3 \rightarrow 7 \rightarrow \color{yellow} 15 \color{gray} \rightarrow \color{yellow} 1 \color{gray}}$$

$${9th: \quad \color{gray} 3 \rightarrow \color{yellow} 7 \color{gray} \rightarrow \color{yellow} 1 \color{gray} \rightarrow 15}$$

$${10th: \quad \color{yellow} 3 \color{gray} \rightarrow \color{yellow} 1 \color{gray} \rightarrow 7 \rightarrow 15}$$

$${11th: \quad \color{gray}1 \rightarrow 3 \rightarrow 7 \rightarrow 15}$$

## After Sorting Algorithm
$${1 \rightarrow 3 \rightarrow 7 \rightarrow 15}$$