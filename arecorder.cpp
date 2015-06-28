#include "arecorder.h"
#include <QUrl>

ARecorder::ARecorder(QObject *parent) : QObject(parent)
{
    q_audioRecorder = new QAudioRecorder(this);
    q_audioRecorder->setOutputLocation(QUrl("/tmp/recording.wav"));
    b_recording = false;
}

const bool &ARecorder::recording() const {
    return b_recording;
}

void ARecorder::record()
{
    if (q_audioRecorder->state() == QMediaRecorder::StoppedState) {
        q_audioRecorder->record();
        b_recording = true;
        emit recordingChanged();
    }
}

void ARecorder::stop() {
    if (q_audioRecorder->state() == QMediaRecorder::RecordingState) {
        q_audioRecorder->stop();
        b_recording = false;
        emit recordingChanged();
    }
}

