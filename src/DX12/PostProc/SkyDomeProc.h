// AMD Cauldron code
// 
// Copyright(c) 2020 Advanced Micro Devices, Inc.All rights reserved.
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
#pragma once

#include "PostProcPS.h"

#include "../../libs/vectormath/vectormath.hpp"

namespace CAULDRON_DX12
{
    // This renders a procedural sky, see the SkyDomeProc.glsl for more references and credits
    class SkyDomeProc
    {
    public:

        struct Constants
        {
            math::Matrix4 invViewProj;
            math::Vector4 vSunDirection;
            float rayleigh;
            float turbidity;
            float mieCoefficient;
            float luminance;
            float mieDirectionalG;
        };

        void OnCreate(Device* pDevice, ResourceViewHeaps *pResourceViewHeaps, DynamicBufferRing *pDynamicBufferRing, StaticBufferPool *pStaticBufferPool, DXGI_FORMAT outFormat, uint32_t sampleDescCount);
        void OnDestroy();
        void Draw(ID3D12GraphicsCommandList* pCommandList, SkyDomeProc::Constants constants);

    private:
        Device            *m_pDevice;

        ResourceViewHeaps *m_pResourceViewHeaps;

        PostProcPS  m_skydome;

        DynamicBufferRing *m_pDynamicBufferRing = NULL;
    };
}
