# Week3
今週はImage型のtopicをsubscribeして、画像を処理したあとpublishしてみましょう.
# 準備
sudo apt install ros-noetic-usb-cam <br>
sudo apt install ros-noetic-image-view<br>
## asusのカメラを使う場合
sudo apt install ros-noetic-openni2-launch<br>
これでだめだったら、<br>
sudo apt install ros-noetic-openni2-camera<br>
# 参考プログラム
week3/scripts/RGB2GRAY.pyを見てください。
ROSのmsgのImg型はそのままopencvを使えないので、CvBridgeを使って変換してから処理します。
publishするときもCvBridgeを使ってImg型のmsgに変換します。
# 参考プログラムの使い方
- ターミナル1でroscore
- usbカメラを使う場合、ターミナル2でソースしたあと、rosrun usb_cam usb_cam_node<br>
- asusカメラを使う場合、ターミナル2でソースしたあと、roslaunch openni2_launch openni2.launch
- ターミナル3でソースしたあと、rosrun week3 RGB2GRAY  
- ターミナル4でrvizを実行してから確認
## 注意
asusカメラを使う場合トピック名が変わってるから修正が必要です。
# 課題
リアルタイムで顔検出します。
opencvには標準で顔検出できるパッケージがあるので探してみてください。
カスケード分類器とか探したらあるやろ。
