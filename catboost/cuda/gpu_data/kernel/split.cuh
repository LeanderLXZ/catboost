#include <catboost/cuda/cuda_lib/kernel/kernel.cuh>
#include <catboost/cuda/gpu_data/gpu_structures.h>

namespace NKernel {

    void WriteCompressedSplit(TCFeature feature, ui32 binIdx,
                              const uint* compressedIndex, ui32 dataSetSize,
                              const ui32* indices, int size,
                              ui64* compressedBits,
                              TCudaStream stream);

    void WriteCompressedSplitFloat(const float* values, float border,
                                   const ui32* indices, int size,
                                   ui64* compressedBits,
                                   TCudaStream stream);

    void UpdateBins(const ui64* compressedBits,
                    ui32 depth,
                    ui32* bins, int size,
                    TCudaStream stream);

}
