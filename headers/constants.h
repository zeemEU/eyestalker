//  Copyright (C) 2016  Terence Brouns

//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.

//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.

//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>

#ifndef CONSTANTS_H
#define CONSTANTS_H

#ifdef __linux__
#else
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#endif

const int    curvatureWindowLength = 10; // window length for curvature
const double edgeCollectionFraction = 0.40;
const double minimumFitFraction = 0.50;
const double minimumRefinementFraction = 0.05;
const int    edgeIntensityPositionOffset = 2;

const double aspectRatioMinIni = 0.4;
const double aspectRatioIni    = 0.9;

const double edgeIntensityIni = 255;
const double CircumferenceUpperLimit = 500;
const double radiusPredictionFactor = 0.75;

const double pupilHaarReductionFactor = 0.75;

const int cameraFrameRateUpperLimit = 500;

const double pupilImageFactor = 1.05;

// initial values for parameters



#endif
