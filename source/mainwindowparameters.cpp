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

#include "headers/mainwindow.h"

void MainWindow::loadSettings(QString filename)
{
    QSettings settings(filename, QSettings::IniFormat);

    cameraAOIFractionHght           = settings.value("CamAOIHghtFraction",          cameraAOIFractionHghtDefaultLeft).toDouble();
    cameraAOIFractionWdth           = settings.value("CamAOIWdthFraction",          cameraAOIFractionWdthDefaultLeft).toDouble();
    cameraAOIFractionXPos           = settings.value("CamAOIXPosFraction",          cameraAOIFractionXPosDefaultLeft).toDouble();
    cameraAOIFractionYPos           = settings.value("CamAOIYPosFraction",          cameraAOIFractionYPosDefaultLeft).toDouble();
    cameraFrameRateDesired          = settings.value("CameraFrameRateDesired",      250).toInt();
    cameraSubSamplingFactor         = settings.value("SubSamplingFactor",           1).toInt();
    dataDirectory                   = settings.value("DataDirectory",               "").toString().toStdString();
    dataDirectoryOffline            = settings.value("DataDirectoryOffline",        "").toString();
    dataFilename                    = settings.value("DataFilename",                "experiment_data").toString().toStdString();
    trialIndexOffline               = settings.value("trialIndexOffline",           0).toInt();
    imageTotalOffline               = settings.value("imageTotalOffline",           0).toInt();
    editSubjectName                 = settings.value("SubjectName",                 "").toString();
    eyeAOIHghtFraction              = settings.value("AOIHghtFraction",             1.0).toDouble();
    eyeAOIWdthFraction              = settings.value("AOIWdthFraction",             1.0).toDouble();
    beadAOIHghtFraction             = settings.value("AOIBeadHghtFraction",         0.3).toDouble();
    beadAOIWdthFraction             = settings.value("AOIBeadWdthFraction",         0.3).toDouble();
    flashThreshold                  = settings.value("FlashThreshold",              230).toInt();
    GAIN_AUTO                       = settings.value("GainAuto",                    true).toBool();
    GAIN_BOOST                      = settings.value("GainBoost",                   false).toBool();
    Parameters::eyeAOIXPosFraction  = settings.value("AOIXPosRelative",             0.0).toDouble();
    Parameters::eyeAOIYPosFraction  = settings.value("AOIYPosRelative",             0.0).toDouble();
    Parameters::beadAOIXPosFraction = settings.value("AOIBeadXPosRelative",         0.2).toDouble();
    Parameters::beadAOIYPosFraction = settings.value("AOIBeadYPosRelative",         0.5).toDouble();
    flashAOIHght                    = settings.value("FlashAOIHght",                100).toInt();
    flashAOIWdth                    = settings.value("FlashAOIWdth",                60).toInt();
    flashAOIXPos                    = settings.value("FlashAOIXPos",                227).toInt();
    flashAOIYPos                    = settings.value("FlashAOIYPos",                500).toInt();
    SAVE_ASPECT_RATIO               = settings.value("SaveAspectRatio",             false).toBool();
    SAVE_CIRCUMFERENCE              = settings.value("SaveCircumference",           false).toBool();
    SAVE_POSITION                   = settings.value("SavePosition",                true).toBool();
    SAVE_EYE_IMAGE                  = settings.value("SaveEyeImage",                true).toBool();
    subjectIdentifier               = settings.value("SubjectIdentifier",           "").toString();
    trialTimeLength                 = settings.value("TrialTimeLength",             1500).toInt();

    detectionParameters mDetectionParametersEye;

    mDetectionParametersEye.alphaAverage                       = settings.value("AlphaAverage",                    0.005).toDouble();
    mDetectionParametersEye.alphaMiscellaneous                 = settings.value("AlphaMiscellaneous",              0.75).toDouble();
    mDetectionParametersEye.alphaMomentum                      = settings.value("AlphaMomentum",                   0.50).toDouble();
    mDetectionParametersEye.alphaPrediction                    = settings.value("AlphaPrediction",                 0.75).toDouble();
    mDetectionParametersEye.cannyBlurLevel                     = settings.value("CannyBlurLevel",                  4).toInt();
    mDetectionParametersEye.cannyKernelSize                    = settings.value("CannyKernelSize",                 5).toInt();
    mDetectionParametersEye.cannyThresholdLow                  = settings.value("CannyThresholdLow",               75).toInt();
    mDetectionParametersEye.cannyThresholdHigh                 = settings.value("CannyThresholdHigh",              150).toInt();
    mDetectionParametersEye.curvatureOffset                    = settings.value("CurvatureOffset",                 10).toDouble();
    mDetectionParametersEye.edgeIntensityOffset                = settings.value("EdgeIntensityOffset",             40).toDouble();
    mDetectionParametersEye.edgeLengthFraction                 = settings.value("EdgeLengthFraction",              0.60).toDouble();
    mDetectionParametersEye.ellipseFitNumberMaximum            = settings.value("EllipseFitNumberMaximum",         3).toInt();
    mDetectionParametersEye.ellipseFitErrorMaximum             = settings.value("EllipseFitErrorMaximum",          80).toDouble();
    mDetectionParametersEye.glintSize                          = settings.value("GlintSize",                       12).toInt();
    mDetectionParametersEye.circumferenceMax                   = settings.value("CircumferenceMax",                320).toDouble();
    mDetectionParametersEye.circumferenceMin                   = settings.value("CircumferenceMin",                60).toDouble();
    mDetectionParametersEye.aspectRatioMin                     = settings.value("AspectRatioMin",                  0.4).toDouble();
    mDetectionParametersEye.pupilOffset                        = settings.value("PupilOffset",                     25).toInt();
    mDetectionParametersEye.circumferenceChangeThreshold       = settings.value("CircumferenceChangeThreshold",    30.0).toDouble();
    mDetectionParametersEye.aspectRatioChangeThreshold         = settings.value("AspectRatioChangeThreshold",      0.2).toDouble();

    mParameterWidgetEye ->setStructure(mDetectionParametersEye);
    mVariableWidgetEye->resetStructure(mDetectionParametersEye);

    detectionParameters mDetectionParametersBead;

    mDetectionParametersBead.alphaAverage                       = settings.value("BeadAlphaAverage",                    0.005).toDouble();
    mDetectionParametersBead.alphaMiscellaneous                 = settings.value("BeadAlphaMiscellaneous",              0.75).toDouble();
    mDetectionParametersBead.alphaMomentum                      = settings.value("BeadAlphaMomentum",                   0.50).toDouble();
    mDetectionParametersBead.alphaPrediction                    = settings.value("BeadAlphaPrediction",                 0.75).toDouble();
    mDetectionParametersBead.cannyBlurLevel                     = settings.value("BeadCannyBlurLevel",                  4).toInt();
    mDetectionParametersBead.cannyKernelSize                    = settings.value("BeadCannyKernelSize",                 5).toInt();
    mDetectionParametersBead.cannyThresholdLow                  = settings.value("BeadCannyThresholdLow",               75).toInt();
    mDetectionParametersBead.cannyThresholdHigh                 = settings.value("BeadCannyThresholdHigh",              150).toInt();
    mDetectionParametersBead.curvatureOffset                    = settings.value("BeadCurvatureOffset",                 10).toDouble();
    mDetectionParametersBead.edgeIntensityOffset                = settings.value("BeadEdgeIntensityOffset",             40).toDouble();
    mDetectionParametersBead.edgeLengthFraction                 = settings.value("BeadEdgeLengthFraction",              0.60).toDouble();
    mDetectionParametersBead.ellipseFitNumberMaximum            = settings.value("BeadEllipseFitNumberMaximum",         3).toInt();
    mDetectionParametersBead.ellipseFitErrorMaximum             = settings.value("BeadEllipseFitErrorMaximum",          80).toDouble();
    mDetectionParametersBead.glintSize                          = settings.value("BeadGlintSize",                       12).toInt();
    mDetectionParametersBead.circumferenceMax                   = settings.value("BeadCircumferenceMax",                320).toDouble();
    mDetectionParametersBead.circumferenceMin                   = settings.value("BeadCircumferenceMin",                60).toDouble();
    mDetectionParametersBead.aspectRatioMin                     = settings.value("BeadAspectRatioMin",                  0.4).toDouble();
    mDetectionParametersBead.pupilOffset                        = settings.value("BeadPupilOffset",                     25).toInt();
    mDetectionParametersBead.circumferenceChangeThreshold       = settings.value("BeadCircumferenceChangeThreshold",    30.0).toDouble();
    mDetectionParametersBead.aspectRatioChangeThreshold         = settings.value("BeadAspectRatioChangeThreshold",      0.2).toDouble();

    mParameterWidgetBead ->setStructure(mDetectionParametersBead);
    mVariableWidgetBead->resetStructure(mDetectionParametersBead);
}

void MainWindow::saveSettings(QString filename)
{
    detectionParameters mDetectionParametersEye  = mParameterWidgetEye->getStructure();
    detectionParameters mDetectionParametersBead = mParameterWidgetBead->getStructure(); // turn this into function

    QSettings settings(filename, QSettings::IniFormat);

    settings.setValue("AOIHghtFraction",                eyeAOIHghtFraction);
    settings.setValue("AOIWdthFraction",                eyeAOIWdthFraction);
    settings.setValue("AOIXPosRelative",                Parameters::eyeAOIXPosFraction);
    settings.setValue("AOIYPosRelative",                Parameters::eyeAOIYPosFraction);
    settings.setValue("AOIBeadHghtFraction",            beadAOIHghtFraction);
    settings.setValue("AOIBeadWdthFraction",            beadAOIWdthFraction);
    settings.setValue("AOIBeadXPosRelative",            Parameters::beadAOIXPosFraction);
    settings.setValue("AOIBeadYPosRelative",            Parameters::beadAOIYPosFraction);
    settings.setValue("DataDirectory",                  QString::fromStdString(dataDirectory));
    settings.setValue("DataDirectoryOffline",           dataDirectoryOffline);
    settings.setValue("GainAuto",                       GAIN_AUTO);
    settings.setValue("GainBoost",                      GAIN_BOOST);
    settings.setValue("CamAOIHghtFraction",             cameraAOIFractionHght);
    settings.setValue("CamAOIWdthFraction",             cameraAOIFractionWdth);
    settings.setValue("CamAOIXPosFraction",             cameraAOIFractionXPos);
    settings.setValue("CamAOIYPosFraction",             cameraAOIFractionYPos);
    settings.setValue("CameraFrameRateDesired",         cameraFrameRateDesired);
    settings.setValue("DataFilename",                   QString::fromStdString(dataFilename));
    settings.setValue("FlashAOIHght",                   flashAOIHght);
    settings.setValue("FlashAOIWdth",                   flashAOIWdth);
    settings.setValue("FlashAOIXPos",                   flashAOIXPos);
    settings.setValue("FlashAOIYPos",                   flashAOIYPos);
    settings.setValue("FlashThreshold",                 flashThreshold);
    settings.setValue("SaveAspectRatio",                SAVE_ASPECT_RATIO);
    settings.setValue("SaveCircumference",              SAVE_CIRCUMFERENCE);
    settings.setValue("SavePosition",                   SAVE_POSITION);
    settings.setValue("SaveEyeImage",                   SAVE_EYE_IMAGE);
    settings.setValue("SubjectName",                    subjectIdentifier);
    settings.setValue("SubSamplingFactor",              cameraSubSamplingFactor);
    settings.setValue("TrialTimeLength",                TrialTimeLengthLineEdit->text().toInt());

    settings.setValue("AlphaAverage",                   mDetectionParametersEye.alphaAverage);
    settings.setValue("AlphaMiscellaneous",             mDetectionParametersEye.alphaMiscellaneous);
    settings.setValue("AlphaMomentum",                  mDetectionParametersEye.alphaMomentum);
    settings.setValue("AlphaPrediction",                mDetectionParametersEye.alphaPrediction);
    settings.setValue("CannyBlurLevel",                 mDetectionParametersEye.cannyBlurLevel);
    settings.setValue("CannyKernelSize",                mDetectionParametersEye.cannyKernelSize);
    settings.setValue("CannyThresholdLow",              mDetectionParametersEye.cannyThresholdLow);
    settings.setValue("CannyThresholdHigh",             mDetectionParametersEye.cannyThresholdHigh);
    settings.setValue("CircumferenceMax",               mDetectionParametersEye.circumferenceMax);
    settings.setValue("CircumferenceMin",               mDetectionParametersEye.circumferenceMin);
    settings.setValue("CurvatureOffset",                mDetectionParametersEye.curvatureOffset);
    settings.setValue("EdgeIntensityOffset",            mDetectionParametersEye.edgeIntensityOffset);
    settings.setValue("EllipseFitNumberMaximum",        mDetectionParametersEye.ellipseFitNumberMaximum);
    settings.setValue("EllipseFitErrorMaximum",         mDetectionParametersEye.ellipseFitErrorMaximum);
    settings.setValue("AspectRatioMin",                 mDetectionParametersEye.aspectRatioMin);
    settings.setValue("GlintSize",                      mDetectionParametersEye.glintSize);
    settings.setValue("PupilOffset",                    mDetectionParametersEye.pupilOffset);
    settings.setValue("CircumferenceChangeThreshold",   mDetectionParametersEye.circumferenceChangeThreshold);
    settings.setValue("AspectRatioChangeThreshold",     mDetectionParametersEye.aspectRatioChangeThreshold);

    settings.setValue("BeadAlphaAverage",                   mDetectionParametersBead.alphaAverage);
    settings.setValue("BeadAlphaMiscellaneous",             mDetectionParametersBead.alphaMiscellaneous);
    settings.setValue("BeadAlphaMomentum",                  mDetectionParametersBead.alphaMomentum);
    settings.setValue("BeadAlphaPrediction",                mDetectionParametersBead.alphaPrediction);
    settings.setValue("BeadCannyBlurLevel",                 mDetectionParametersBead.cannyBlurLevel);
    settings.setValue("BeadCannyKernelSize",                mDetectionParametersBead.cannyKernelSize);
    settings.setValue("BeadCannyThresholdLow",              mDetectionParametersBead.cannyThresholdLow);
    settings.setValue("BeadCannyThresholdHigh",             mDetectionParametersBead.cannyThresholdHigh);
    settings.setValue("BeadCircumferenceMax",               mDetectionParametersBead.circumferenceMax);
    settings.setValue("BeadCircumferenceMin",               mDetectionParametersBead.circumferenceMin);
    settings.setValue("BeadCurvatureOffset",                mDetectionParametersBead.curvatureOffset);
    settings.setValue("BeadEdgeIntensityOffset",            mDetectionParametersBead.edgeIntensityOffset);
    settings.setValue("BeadEllipseFitNumberMaximum",        mDetectionParametersBead.ellipseFitNumberMaximum);
    settings.setValue("BeadEllipseFitErrorMaximum",         mDetectionParametersBead.ellipseFitErrorMaximum);
    settings.setValue("BeadAspectRatioMin",                 mDetectionParametersBead.aspectRatioMin);
    settings.setValue("BeadGlintSize",                      mDetectionParametersBead.glintSize);
    settings.setValue("BeadPupilOffset",                    mDetectionParametersBead.pupilOffset);
    settings.setValue("BeadCircumferenceChangeThreshold",   mDetectionParametersBead.circumferenceChangeThreshold);
    settings.setValue("BeadAspectRatioChangeThreshold",     mDetectionParametersBead.aspectRatioChangeThreshold);
}

void MainWindow::onResetParameters()
{
    QString text = "Do you wish to reset all parameters to their default values?";
    ConfirmationWindow mConfirmationWindow(text);
    mConfirmationWindow.setWindowTitle("Please select option");

    if(mConfirmationWindow.exec() == QDialog::Rejected) { return; }

    QString filename = "";
    loadSettings(filename);
    mParameterWidgetEye->reset();
    mVariableWidgetEye->resetStructure(mParameterWidgetEye->getStructure());
}

void MainWindow::startRecordingManual()
{
    if (!FLASH_STANDBY) { startTrialRecording(); }
}

void MainWindow::setBeadDetection(int state)
{
    int index = 2 + (int) Parameters::ONLINE_PROCESSING;

    if (state)
    {
        MainTabWidget->setUpdatesEnabled(false);
        MainTabWidget->insertTab(index, BeadTrackingScrollArea, tr("Bead-tracking"));
        MainTabWidget->setUpdatesEnabled(true);
        mParameterWidgetBead->setState(true);
    }
    else
    {
        MainTabWidget->removeTab(index);
        mParameterWidgetBead->setState(false);
    }
}

void MainWindow::onSetRealTime(int state)
{
    if (state) { SAVE_EYE_IMAGE = false; }
    else       { SAVE_EYE_IMAGE = true;  }
}

void MainWindow::setFlashStandby(bool flag)
{
    std::lock_guard<std::mutex> mainMutexLock(Parameters::mainMutex);
    FLASH_STANDBY = flag;
}

void MainWindow::onFlashStandbySlider(int val)
{
    if (Parameters::CAMERA_RUNNING)
    {
        if (val == 0)
        {
            setFlashStandby(false);
            FlashStandbyLabel->setText("<font color='red'><b>OFF</b></font>");

            if (CameraHardwareGainAutoCheckBox->isChecked())
            {
                mUEyeOpencvCam.setAutoGain(true);
            }
        }
        else
        {
            dataFilename = (DataFilenameLineEdit->text()).toStdString();

            std::stringstream filename;
            filename << dataDirectory
                     << "/"
                     << dataFilename
                     << ".dat";

            if (boost::filesystem::exists(filename.str()))
            {
                QString text = "The file <b>" + QString::fromStdString(dataFilename) + ".dat</b> already exists in <b>" + QString::fromStdString(dataDirectory) + "/</b>. Do you wish to add data to the end of this file?";
                ConfirmationWindow mConfirmationWindow(text);
                mConfirmationWindow.setWindowTitle("Please select option");

                if(mConfirmationWindow.exec() == QDialog::Rejected)
                {
                    FlashStandbySlider->setValue(0);
                    return;
                }
            }

            setFlashStandby(true);
            FlashStandbyLabel->setText("<font color='green'><b>ON</b></font>");

            if (CameraHardwareGainAutoCheckBox->isChecked())
            {
                mUEyeOpencvCam.setAutoGain(false);
            }
        }
    }
    else
    {
        FlashStandbySlider->setValue(0);
    }
}

void MainWindow::onResetFlashIntensity()
{
    flashMinIntensity = 0;
    FlashThresholdSlider->setMinimum(0);
    FlashThresholdSlider->setValue(0);
}


void MainWindow::setCameraPixelClock(int value)
{
    cameraPixelClock = value;
    mUEyeOpencvCam.setPixelClock(cameraPixelClock);
    CameraPixelClockLabel->setText(QString::number(cameraPixelClock));

    // Set new frame rate

    std::vector<double> frameRateRange = mUEyeOpencvCam.getFrameRateRange();
    CameraFrameRateSlider->setDoubleRange(frameRateRange[0], frameRateRange[1]);
    CameraFrameRateSlider->setDoubleValue(frameRateRange[1]);
    setCameraFrameRate(frameRateRange[1]); // set frame-rate to maximum
}

void MainWindow::setCameraFrameRate(double value)
{
    cameraFrameRate = mUEyeOpencvCam.setFrameRate(value);
    CameraFrameRateLabel->setText(QString::number(cameraFrameRate, 'f', 1));

    // Set new exposure

    std::vector<double> exposureRange = mUEyeOpencvCam.getExposureRange();
    CameraExposureSlider->setDoubleRange(exposureRange[0], exposureRange[1]);
    CameraExposureSlider->setDoubleValue(exposureRange[1]);
    setCameraExposure(exposureRange[1]);
}

void MainWindow::setCameraExposure(double value)
{
    mUEyeOpencvCam.setExposure(value);
    CameraExposureLabel->setText(QString::number(value, 'f', 2));
}

void MainWindow::setCameraBlackLevelOffset(int value)
{
    double blackLevelOffset = mUEyeOpencvCam.setBlackLevelOffset(value);
    CameraBlackLevelOffsetLabel->setText(QString::number(blackLevelOffset));
}

void MainWindow::setCameraBlackLevelMode(int state)
{
    if (state) { mUEyeOpencvCam.setBlackLevelMode(true);  }
    else       { mUEyeOpencvCam.setBlackLevelMode(false); }
}

void MainWindow::setCameraGainBoost(int state)
{
    if (state) { mUEyeOpencvCam.setGainBoost(true);  }
    else       { mUEyeOpencvCam.setGainBoost(false); }
}

void MainWindow::setCameraAutoGain(int state)
{
    if (state)
    {
        GAIN_AUTO = true;
        mUEyeOpencvCam.setAutoGain(true);
    }
    else
    {
        GAIN_AUTO = false;
        mUEyeOpencvCam.setAutoGain(false);
    }
}

void MainWindow::setCameraHardwareGain(int val)
{
    if (!CameraHardwareGainAutoCheckBox->checkState())
    {
        mUEyeOpencvCam.setHardwareGain(val);
    }

    CameraHardwareGainLabel->setText(QString::number(val));
}

void MainWindow::setCameraSubSampling(int state)
{
    double subSamplingChange = 0;

    if (state == 1)
    {
        subSamplingChange = 0.5 * cameraSubSamplingFactor;
        cameraSubSamplingFactor = 2;
    }
    else if (state == 0)
    {
        subSamplingChange = cameraSubSamplingFactor;
        cameraSubSamplingFactor = 1;
    }

    cameraAOIWdthMax = cameraAOIWdthMax * subSamplingChange;
    cameraAOIHghtMax = cameraAOIHghtMax * subSamplingChange;

    updateCamAOIx();
    updateCamAOIy();

    if (Parameters::CAMERA_RUNNING)
    {
        if (mUEyeOpencvCam.freeImageMemory())
        {
            if (mUEyeOpencvCam.setSubSampling(cameraSubSamplingFactor))
            {
                if (mUEyeOpencvCam.allocateMemory(Parameters::cameraAOIWdth, Parameters::cameraAOIHght))
                {
                    mUEyeOpencvCam.setAOI(Parameters::cameraAOIXPos, Parameters::cameraAOIYPos, Parameters::cameraAOIWdth, Parameters::cameraAOIHght);
                    Parameters::CAMERA_READY = true;
                }
            }
        }

        getCameraParameters();
    }
}

void MainWindow::onCropAOI()
{
    int absXPos = Parameters::eyeAOIXPos + Parameters::cameraAOIXPos;
    int absYPos = Parameters::eyeAOIYPos + Parameters::cameraAOIYPos;

    double fracXPos = absXPos / (double) cameraAOIWdthMax;
    double fracYPos = absYPos / (double) cameraAOIHghtMax;
    double fracWdth = (Parameters::eyeAOIWdth - cameraAOIWdthMin) / (double) (cameraAOIWdthMax - cameraAOIWdthMin);
    double fracHght = (Parameters::eyeAOIHght - cameraAOIHghtMin) / (double) (cameraAOIHghtMax - cameraAOIHghtMin);

    Parameters::eyeAOIXPosFraction = 1.0;
    Parameters::eyeAOIYPosFraction = 1.0;
    eyeAOIWdthFraction = 1.0;
    eyeAOIHghtFraction = 1.0;

    CamEyeAOIXPosSlider->setDoubleValue(fracXPos);
    CamEyeAOIYPosSlider->setDoubleValue(fracYPos);
    CamEyeAOIWdthSlider->setDoubleValue(fracWdth);
    CamEyeAOIHghtSlider->setDoubleValue(fracHght);
}

void MainWindow::updateCamAOIx()
{
    Parameters::cameraAOIWdth = floor(((cameraAOIWdthMax - cameraAOIWdthMin) * cameraAOIFractionWdth + cameraAOIWdthMin) / (double) cameraAOIWdthStepSize) * cameraAOIWdthStepSize;
    Parameters::cameraAOIXPos = floor((cameraAOIWdthMax * cameraAOIFractionXPos) / (double) cameraAOIWdthStepSize) * cameraAOIWdthStepSize;
    CamEyeAOIXPosSlider->setDoubleMaximum((cameraAOIWdthMax - Parameters::cameraAOIWdth) / (double) cameraAOIWdthMax);

    { std::lock_guard<std::mutex> mainMutexLock(Parameters::mainMutex);
        updateEyeAOIx(); }
}

void MainWindow::updateCamAOIy()
{
    Parameters::cameraAOIHght = floor(((cameraAOIHghtMax - cameraAOIHghtMin) * cameraAOIFractionHght + cameraAOIHghtMin) / (double) cameraAOIHghtStepSize) * cameraAOIHghtStepSize;
    Parameters::cameraAOIYPos = floor((cameraAOIHghtMax * cameraAOIFractionYPos) / (double) cameraAOIHghtStepSize) * cameraAOIHghtStepSize;
    CamEyeAOIYPosSlider->setDoubleMaximum((cameraAOIHghtMax - Parameters::cameraAOIHght) / (double) cameraAOIHghtMax);

    { std::lock_guard<std::mutex> mainMutexLock(Parameters::mainMutex);
        updateEyeAOIy(); }
}

void MainWindow::updateEyeAOIx()
{
    Parameters::eyeAOIWdth = round(Parameters::cameraAOIWdth * eyeAOIWdthFraction);
    Parameters::eyeAOIXPos = round(Parameters::cameraAOIWdth * Parameters::eyeAOIXPosFraction);

    if (Parameters::eyeAOIXPos + Parameters::eyeAOIWdth > Parameters::cameraAOIWdth)
    {   Parameters::eyeAOIXPos = Parameters::cameraAOIWdth - Parameters::eyeAOIWdth; }

    Parameters::beadAOIWdth = round(Parameters::cameraAOIWdth * beadAOIWdthFraction);
    Parameters::beadAOIXPos = round(Parameters::cameraAOIWdth * Parameters::beadAOIXPosFraction);

    if (Parameters::beadAOIXPos + Parameters::beadAOIWdth > Parameters::cameraAOIWdth)
    {   Parameters::beadAOIXPos = Parameters::cameraAOIWdth - Parameters::beadAOIWdth; }
}

void MainWindow::updateEyeAOIy()
{
    Parameters::eyeAOIHght = round(Parameters::cameraAOIHght * eyeAOIHghtFraction);
    Parameters::eyeAOIYPos = round(Parameters::cameraAOIHght * Parameters::eyeAOIYPosFraction);

    if (Parameters::eyeAOIYPos + Parameters::eyeAOIHght > Parameters::cameraAOIHght)
    {   Parameters::eyeAOIYPos = Parameters::cameraAOIHght - Parameters::eyeAOIHght; }

    Parameters::beadAOIHght = round(Parameters::cameraAOIHght * beadAOIHghtFraction);
    Parameters::beadAOIYPos = round(Parameters::cameraAOIHght * Parameters::beadAOIYPosFraction);

    if (Parameters::beadAOIYPos + Parameters::beadAOIHght > Parameters::cameraAOIHght)
    {   Parameters::beadAOIYPos = Parameters::cameraAOIHght - Parameters::beadAOIHght; }
}

void MainWindow::setCamEyeAOIWdth(double fraction)
{
    { std::lock_guard<std::mutex> mainMutexLock(Parameters::mainMutex);
        cameraAOIFractionWdth = fraction;
        Parameters::cameraAOIWdth = floor(((cameraAOIWdthMax - cameraAOIWdthMin) * cameraAOIFractionWdth + cameraAOIWdthMin) / (double) cameraAOIWdthStepSize) * cameraAOIWdthStepSize;
        updateEyeAOIx(); }

    if (mUEyeOpencvCam.freeImageMemory())
    {
        if (mUEyeOpencvCam.allocateMemory(Parameters::cameraAOIWdth, Parameters::cameraAOIHght))
        {
            if (Parameters::cameraAOIXPos + Parameters::cameraAOIWdth <= cameraAOIWdthMax)
            {
                if (mUEyeOpencvCam.setAOI(Parameters::cameraAOIXPos, Parameters::cameraAOIYPos, Parameters::cameraAOIWdth, Parameters::cameraAOIHght))
                {
                    Parameters::CAMERA_READY = true;
                    getCameraParameters();
                }
            }
        }
    }

    CamEyeAOIXPosSlider->setDoubleMaximum((cameraAOIWdthMax - Parameters::cameraAOIWdth) / (double) cameraAOIWdthMax);
}

void MainWindow::setCamEyeAOIHght(double fraction)
{
    { std::lock_guard<std::mutex> mainMutexLock(Parameters::mainMutex);
        cameraAOIFractionHght = fraction;
        Parameters::cameraAOIHght = floor(((cameraAOIHghtMax - cameraAOIHghtMin) * cameraAOIFractionHght + cameraAOIHghtMin) / (double) cameraAOIHghtStepSize) * cameraAOIHghtStepSize;
        updateEyeAOIy(); }

    if (mUEyeOpencvCam.freeImageMemory())
    {
        if (mUEyeOpencvCam.allocateMemory(Parameters::cameraAOIWdth, Parameters::cameraAOIHght))
        {
            if (Parameters::cameraAOIYPos + Parameters::cameraAOIHght <= cameraAOIHghtMax)
            {
                if (mUEyeOpencvCam.setAOI(Parameters::cameraAOIXPos, Parameters::cameraAOIYPos, Parameters::cameraAOIWdth, Parameters::cameraAOIHght))
                {
                    Parameters::CAMERA_READY = true;
                    getCameraParameters();
                }
            }
        }
    }

    CamEyeAOIYPosSlider->setDoubleMaximum((cameraAOIHghtMax - Parameters::cameraAOIHght) / (double) cameraAOIHghtMax);
}

void MainWindow::setCamEyeAOIXPos(double fraction)
{
    cameraAOIFractionXPos = fraction;

    Parameters::cameraAOIXPos = floor((cameraAOIWdthMax * cameraAOIFractionXPos) / (double) cameraAOIWdthStepSize) * cameraAOIWdthStepSize;

    if (mUEyeOpencvCam.setAOI(Parameters::cameraAOIXPos, Parameters::cameraAOIYPos, Parameters::cameraAOIWdth, Parameters::cameraAOIHght))
    {
        Parameters::CAMERA_READY = true;
        getCameraParameters();
    }
}

void MainWindow::setCamEyeAOIYPos(double fraction)
{
    cameraAOIFractionYPos = fraction;

    Parameters::cameraAOIYPos = floor((cameraAOIHghtMax * cameraAOIFractionYPos) / (double) cameraAOIHghtStepSize) * cameraAOIHghtStepSize;

    if (mUEyeOpencvCam.setAOI(Parameters::cameraAOIXPos, Parameters::cameraAOIYPos, Parameters::cameraAOIWdth, Parameters::cameraAOIHght))
    {
        Parameters::CAMERA_READY = true;
        getCameraParameters();
    }
}

void MainWindow::setEyeAOIWdth(double fraction)
{
    std::lock_guard<std::mutex> mainMutexLock(Parameters::mainMutex);

    eyeAOIWdthFraction = fraction;

    Parameters::eyeAOIWdth = round(Parameters::cameraAOIWdth * eyeAOIWdthFraction);

    if (Parameters::eyeAOIXPos + Parameters::eyeAOIWdth > Parameters::cameraAOIWdth)
    {   Parameters::eyeAOIXPos = Parameters::cameraAOIWdth - Parameters::eyeAOIWdth; }
}

void MainWindow::setEyeAOIHght(double fraction)
{
    std::lock_guard<std::mutex> mainMutexLock(Parameters::mainMutex);

    eyeAOIHghtFraction = fraction;

    Parameters::eyeAOIHght = round(Parameters::cameraAOIHght * eyeAOIHghtFraction);

    if (Parameters::eyeAOIYPos + Parameters::eyeAOIHght > Parameters::cameraAOIHght)
    {   Parameters::eyeAOIYPos = Parameters::cameraAOIHght - Parameters::eyeAOIHght; }
}

void MainWindow::setFlashAOIXPos(int val)
{
    std::lock_guard<std::mutex> mainMutexLock(Parameters::mainMutex);

    flashAOIXPos = val;
    CamQImage->setAOIFlash(flashAOIXPos, flashAOIYPos, flashAOIWdth, flashAOIHght);
}

void MainWindow::setFlashAOIYPos(int val)
{
    std::lock_guard<std::mutex> mainMutexLock(Parameters::mainMutex);

    flashAOIYPos = val;
    CamQImage->setAOIFlash(flashAOIXPos, flashAOIYPos, flashAOIWdth, flashAOIHght);
}

void MainWindow::setFlashAOIWdth(int val)
{
    std::lock_guard<std::mutex> mainMutexLock(Parameters::mainMutex);

    flashAOIWdth = val;
    CamQImage->setAOIFlash(flashAOIXPos, flashAOIYPos, flashAOIWdth, flashAOIHght);
}

void MainWindow::setFlashAOIHght(int val)
{
    std::lock_guard<std::mutex> mainMutexLock(Parameters::mainMutex);

    flashAOIHght = val;
    CamQImage->setAOIFlash(flashAOIXPos, flashAOIYPos, flashAOIWdth, flashAOIHght);
}

void MainWindow::setFlashThreshold(int val)
{
    flashThreshold = val;
    FlashThresholdLabel->setText(QString::number(flashThreshold));
}

void MainWindow::onSetTrialIndex(int val)
{
    trialIndex = val;
}

void MainWindow::setSaveDataAspectRatio(int state)
{
    if (state) { SAVE_ASPECT_RATIO = true;  }
    else       { SAVE_ASPECT_RATIO = false; }
}

void MainWindow::setSaveDataCircumference(int state)
{
    if (state) { SAVE_CIRCUMFERENCE = true;  }
    else       { SAVE_CIRCUMFERENCE = false; }
}

void MainWindow::setSaveDataPosition(int state)
{
    if (state) { SAVE_POSITION = true;  }
    else       { SAVE_POSITION = false; }
}

void MainWindow::onSetAOIEyeLeft()
{
    CamEyeAOIXPosSlider->setDoubleValue(cameraAOIFractionXPosDefaultLeft);
    CamEyeAOIYPosSlider->setDoubleValue(cameraAOIFractionYPosDefaultLeft);
    CamEyeAOIWdthSlider->setDoubleValue(cameraAOIFractionWdthDefaultLeft);
    CamEyeAOIHghtSlider->setDoubleValue(cameraAOIFractionHghtDefaultLeft);
}

void MainWindow::onSetAOIEyeRght()
{
    CamEyeAOIXPosSlider->setDoubleValue(cameraAOIFractionXPosDefaultRght);
    CamEyeAOIYPosSlider->setDoubleValue(cameraAOIFractionYPosDefaultRght);
    CamEyeAOIWdthSlider->setDoubleValue(cameraAOIFractionWdthDefaultRght);
    CamEyeAOIHghtSlider->setDoubleValue(cameraAOIFractionHghtDefaultRght);
}

void MainWindow::setDrawHaar(int state)
{
    if (state) { Parameters::drawFlags.haar = true;  }
    else       { Parameters::drawFlags.haar = false; }
}

void MainWindow::setDrawEdge(int state)
{
    if (state) { Parameters::drawFlags.edge = true;  }
    else       { Parameters::drawFlags.edge = false; }
}

void MainWindow::setDrawElps(int state)
{
    if (state) { Parameters::drawFlags.elps = true;  }
    else       { Parameters::drawFlags.elps = false; }
}
