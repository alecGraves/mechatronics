cmake . && \
make -j$(($(expr $(nproc) - 1) > 0 ? $(expr $(nproc) - 1) : 1))
#make using num_cores-1, check if only 1 core available