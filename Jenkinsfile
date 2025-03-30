pipeline {
    agent any
    stages {
        stage('Checkout') {
            steps {
                git 'https://github.com/anujgupta345/CPP_QT_MULTITHREADING_LINUX_1.git'
            }
        }
        stage('Build') {
            steps {
                sh '''
                export QTDIR=/usr/lib/qt5
                export PATH=/usr/lib/qt5/bin:$PATH
                qmake IPC.pro
                mkdir -p build
                make clean && make -j$(nproc)
                '''
            }
        }
        stage('Archive Artifacts') {
            steps {
                archiveArtifacts artifacts: 'build/Desktop_Qt_*/IPC', fingerprint: true
            }
        }
        stage('Deploy') {
            steps {
                sh '''
                chmod +x build/Desktop_Qt_*/IPC
                cp build/Desktop_Qt_*/IPC $WORKSPACE/
                echo "Application deployed successfully!"
                '''
            }
        }
        stage('Run Application') {
            steps {
                sh '''
                export DISPLAY=:0
                nohup $WORKSPACE/IPC >$WORKSPACE/app.log 2>&1 &
                echo "Application started in background!"
                '''
            }
        }
    }
}
