This is a Toolkit for calculating complex matrices, intended for use in ROOT macro.(https://root.cern.ch/)
You can Declare complex number a+bi as,
		Complex z=Complex(a+bi);
And N-dimensional Complex Matrix as
		CMatND A=CMatND(Z);
where Z should be NxN array of Complex numbers, and N ranges from 2-4.
Currently the code supports matrix product/summation/subtraction, making Minor matrix, taking transpose, inverse and determinant.(ofcourse, in Complex number).
Eigenvalue problem is not supported yet.
You can contact me vie email kangbm@korea.ac.kr
