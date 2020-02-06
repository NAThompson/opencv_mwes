CXX=clang++
INCFLAGS=-I/usr/local/include/opencv4
LINKFLAGS=$(pkg-config --cflags --libs opencv4)
all: example.x

example.x: example.cpp
	$(CXX)  -g --std=c++17 -fsanitize=address -fsanitize=undefined -I/usr/local/Cellar/opencv/4.2.0_1/include/opencv4/opencv -I/usr/local/Cellar/opencv/4.2.0_1/include/opencv4 -c example.cpp
	$(CXX) -g --std=c++17 -fsanitize=address -fsanitize=undefined -o example.x example.o -L/usr/local/Cellar/opencv/4.2.0_1/lib -lopencv_gapi -lopencv_stitching -lopencv_gapi -lopencv_stitching -lopencv_aruco -lopencv_bgsegm -lopencv_bioinspired -lopencv_ccalib -lopencv_dnn_objdetect -lopencv_dnn_superres -lopencv_dpm -lopencv_highgui -lopencv_face -lopencv_freetype -lopencv_fuzzy -lopencv_hfs -lopencv_img_hash -lopencv_line_descriptor -lopencv_quality -lopencv_reg -lopencv_rgbd -lopencv_saliency -lopencv_sfm -lopencv_stereo -lopencv_structured_light -lopencv_phase_unwrapping -lopencv_superres -lopencv_optflow -lopencv_surface_matching -lopencv_tracking -lopencv_datasets -lopencv_text -lopencv_dnn -lopencv_plot -lopencv_videostab -lopencv_videoio -lopencv_xfeatures2d -lopencv_shape -lopencv_ml -lopencv_ximgproc -lopencv_video -lopencv_xobjdetect -lopencv_objdetect -lopencv_calib3d -lopencv_imgcodecs -lopencv_features2d -lopencv_flann -lopencv_xphoto -lopencv_photo -lopencv_imgproc -lopencv_core

clean:
	rm -f *.x *.o a.out output.*
