// File: Asm_x86_64_Jitdb.cpp
// Author: Mario
// Created: 07.27.2021 5:38 PM
// Project: NominaxRuntime
// 
//                                  Apache License
//                            Version 2.0, January 2004
//                         http://www.apache.org/licenses/
// 
//    TERMS AND CONDITIONS FOR USE, REPRODUCTION, AND DISTRIBUTION
// 
//    1. Definitions.
// 
//       "License" shall mean the terms and conditions for use, reproduction,
//       and distribution as defined by Sections 1 through 9 of this document.
// 
//       "Licensor" shall mean the copyright owner or entity authorized by
//       the copyright owner that is granting the License.
// 
//       "Legal Entity" shall mean the union of the acting entity and all
//       other entities that control, are controlled by, or are under common
//       control with that entity. For the purposes of this definition,
//       "control" means (i) the power, direct or indirect, to cause the
//       direction or management of such entity, whether by contract or
//       otherwise, or (ii) ownership of fifty percent (50%) or more of the
//       outstanding shares, or (iii) beneficial ownership of such entity.
// 
//       "You" (or "Your") shall mean an individual or Legal Entity
//       exercising permissions granted by this License.
// 
//       "Source" form shall mean the preferred form for making modifications,
//       including but not limited to software source code, documentation
//       source, and configuration files.
// 
//       "Object" form shall mean any form resulting from mechanical
//       transformation or translation of a Source form, including but
//       not limited to compiled object code, generated documentation,
//       and conversions to other media types.
// 
//       "Work" shall mean the work of authorship, whether in Source or
//       Object form, made available under the License, as indicated by a
//       copyright notice that is included in or attached to the work
//       (an example is provided in the Appendix below).
// 
//       "Derivative Works" shall mean any work, whether in Source or Object
//       form, that is based on (or derived from) the Work and for which the
//       editorial revisions, annotations, elaborations, or other modifications
//       represent, as a whole, an original work of authorship. For the purposes
//       of this License, Derivative Works shall not include works that remain
//       separable from, or merely link (or bind by name) to the interfaces of,
//       the Work and Derivative Works thereof.
// 
//       "Contribution" shall mean any work of authorship, including
//       the original version of the Work and any modifications or additions
//       to that Work or Derivative Works thereof, that is intentionally
//       submitted to Licensor for inclusion in the Work by the copyright owner
//       or by an individual or Legal Entity authorized to submit on behalf of
//       the copyright owner. For the purposes of this definition, "submitted"
//       means any form of electronic, verbal, or written communication sent
//       to the Licensor or its representatives, including but not limited to
//       communication on electronic mailing lists, source code control systems,
//       and issue tracking systems that are managed by, or on behalf of, the
//       Licensor for the purpose of discussing and improving the Work, but
//       excluding communication that is conspicuously marked or otherwise
//       designated in writing by the copyright owner as "Not a Contribution."
// 
//       "Contributor" shall mean Licensor and any individual or Legal Entity
//       on behalf of whom a Contribution has been received by Licensor and
//       subsequently incorporated within the Work.
// 
//    2. Grant of Copyright License. Subject to the terms and conditions of
//       this License, each Contributor hereby grants to You a perpetual,
//       worldwide, non-exclusive, no-charge, royalty-free, irrevocable
//       copyright license to reproduce, prepare Derivative Works of,
//       publicly display, publicly perform, sublicense, and distribute the
//       Work and such Derivative Works in Source or Object form.
// 
//    3. Grant of Patent License. Subject to the terms and conditions of
//       this License, each Contributor hereby grants to You a perpetual,
//       worldwide, non-exclusive, no-charge, royalty-free, irrevocable
//       (except as stated in this section) patent license to make, have made,
//       use, offer to sell, sell, import, and otherwise transfer the Work,
//       where such license applies only to those patent claims licensable
//       by such Contributor that are necessarily infringed by their
//       Contribution(s) alone or by combination of their Contribution(s)
//       with the Work to which such Contribution(s) was submitted. If You
//       institute patent litigation against any entity (including a
//       cross-claim or counterclaim in a lawsuit) alleging that the Work
//       or a Contribution incorporated within the Work constitutes direct
//       or contributory patent infringement, then any patent licenses
//       granted to You under this License for that Work shall terminate
//       as of the date such litigation is filed.
// 
//    4. Redistribution. You may reproduce and distribute copies of the
//       Work or Derivative Works thereof in any medium, with or without
//       modifications, and in Source or Object form, provided that You
//       meet the following conditions:
// 
//       (a) You must give any other recipients of the Work or
//           Derivative Works a copy of this License; and
// 
//       (b) You must cause any modified files to carry prominent notices
//           stating that You changed the files; and
// 
//       (c) You must retain, in the Source form of any Derivative Works
//           that You distribute, all copyright, patent, trademark, and
//           attribution notices from the Source form of the Work,
//           excluding those notices that do not pertain to any part of
//           the Derivative Works; and
// 
//       (d) If the Work includes a "NOTICE" text file as part of its
//           distribution, then any Derivative Works that You distribute must
//           include a readable copy of the attribution notices contained
//           within such NOTICE file, excluding those notices that do not
//           pertain to any part of the Derivative Works, in at least one
//           of the following places: within a NOTICE text file distributed
//           as part of the Derivative Works; within the Source form or
//           documentation, if provided along with the Derivative Works; or,
//           within a display generated by the Derivative Works, if and
//           wherever such third-party notices normally appear. The contents
//           of the NOTICE file are for informational purposes only and
//           do not modify the License. You may add Your own attribution
//           notices within Derivative Works that You distribute, alongside
//           or as an addendum to the NOTICE text from the Work, provided
//           that such additional attribution notices cannot be construed
//           as modifying the License.
// 
//       You may add Your own copyright statement to Your modifications and
//       may provide additional or different license terms and conditions
//       for use, reproduction, or distribution of Your modifications, or
//       for any such Derivative Works as a whole, provided Your use,
//       reproduction, and distribution of the Work otherwise complies with
//       the conditions stated in this License.
// 
//    5. Submission of Contributions. Unless You explicitly state otherwise,
//       any Contribution intentionally submitted for inclusion in the Work
//       by You to the Licensor shall be under the terms and conditions of
//       this License, without any additional terms or conditions.
//       Notwithstanding the above, nothing herein shall supersede or modify
//       the terms of any separate license agreement you may have executed
//       with Licensor regarding such Contributions.
// 
//    6. Trademarks. This License does not grant permission to use the trade
//       names, trademarks, service marks, or product names of the Licensor,
//       except as required for reasonable and customary use in describing the
//       origin of the Work and reproducing the content of the NOTICE file.
// 
//    7. Disclaimer of Warranty. Unless required by applicable law or
//       agreed to in writing, Licensor provides the Work (and each
//       Contributor provides its Contributions) on an "AS IS" BASIS,
//       WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
//       implied, including, without limitation, any warranties or conditions
//       of TITLE, NON-INFRINGEMENT, MERCHANTABILITY, or FITNESS FOR A
//       PARTICULAR PURPOSE. You are solely responsible for determining the
//       appropriateness of using or redistributing the Work and assume any
//       risks associated with Your exercise of permissions under this License.
// 
//    8. Limitation of Liability. In no event and under no legal theory,
//       whether in tort (including negligence), contract, or otherwise,
//       unless required by applicable law (such as deliberate and grossly
//       negligent acts) or agreed to in writing, shall any Contributor be
//       liable to You for damages, including any direct, indirect, special,
//       incidental, or consequential damages of any character arising as a
//       result of this License or out of the use or inability to use the
//       Work (including but not limited to damages for loss of goodwill,
//       work stoppage, computer failure or malfunction, or any and all
//       other commercial damages or losses), even if such Contributor
//       has been advised of the possibility of such damages.
// 
//    9. Accepting Warranty or Additional Liability. While redistributing
//       the Work or Derivative Works thereof, You may choose to offer,
//       and charge a fee for, acceptance of support, warranty, indemnity,
//       or other liability obligations and/or rights consistent with this
//       License. However, in accepting such obligations, You may act only
//       on Your own behalf and on Your sole responsibility, not on behalf
//       of any other Contributor, and only if You agree to indemnify,
//       defend, and hold each Contributor harmless for any liability
//       incurred by, or claims asserted against, such Contributor by reason
//       of your accepting any such warranty or additional liability.
// 
//    END OF TERMS AND CONDITIONS
// 
//    APPENDIX: How to apply the Apache License to your work.
// 
//       To apply the Apache License to your work, attach the following
//       boilerplate notice, with the fields enclosed by brackets "[]"
//       replaced with your own identifying information. (Don't include
//       the brackets!)  The text should be enclosed in the appropriate
//       comment syntax for the file format. We also recommend that a
//       file or class name and description of purpose be included on the
//       same "printed page" as the copyright notice for easier
//       identification within third-party archives.
// 
//    Copyright 2021 Mario Sieg "pinsrq" <mt3000@gmx.de>
// 
//    Licensed under the Apache License, Version 2.0 (the "License");
//    you may not use this file except in compliance with the License.
//    You may obtain a copy of the License at
// 
//        http://www.apache.org/licenses/LICENSE-2.0
// 
//    Unless required by applicable law or agreed to in writing, software
//    distributed under the License is distributed on an "AS IS" BASIS,
//    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//    See the License for the specific language governing permissions and
//    limitations under the License.

// Auto generated, do not edit!

#include "../Include/Nominax/Asm_x86_64.hpp"

namespace Nominax::Assembler::X86_64
{
NOX_NEVER_INLINE NOX_COLD auto GetVariationTable_8(std::pmr::monotonic_buffer_resource& allocator, std::pmr::vector<InstructionVariationPool>& out) -> void
{
	std::pmr::vector<InstructionVariation> instruction{&allocator};
	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "movhlps",
			.GasMnemonic = "movhlps",
			.Description = "movhlps xmm, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x12,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "movhpd",
			.GasMnemonic = "movhpd",
			.Description = "movhpd xmm, m64",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M64,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x16,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "movhpd",
			.GasMnemonic = "movhpd",
			.Description = "movhpd m64, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M64,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x17,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "movhps",
			.GasMnemonic = "movhps",
			.Description = "movhps xmm, m64",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M64,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x16,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "movhps",
			.GasMnemonic = "movhps",
			.Description = "movhps m64, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M64,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x17,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "movlhps",
			.GasMnemonic = "movlhps",
			.Description = "movlhps xmm, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x16,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "movlpd",
			.GasMnemonic = "movlpd",
			.Description = "movlpd xmm, m64",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M64,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x12,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "movlpd",
			.GasMnemonic = "movlpd",
			.Description = "movlpd m64, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M64,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x13,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "movlps",
			.GasMnemonic = "movlps",
			.Description = "movlps xmm, m64",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M64,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x12,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "movlps",
			.GasMnemonic = "movlps",
			.Description = "movlps m64, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M64,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x13,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "movmskpd",
			.GasMnemonic = "movmskpd",
			.Description = "movmskpd r32, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::R32,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::R32},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x50,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::R32},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "movmskps",
			.GasMnemonic = "movmskps",
			.Description = "movmskps r32, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::R32,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::R32},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x50,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::R32},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "movntdq",
			.GasMnemonic = "movntdq",
			.Description = "movntdq m128, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M128,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xe7,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128},
						.Rm = {OperandType::M128},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "movntdqa",
			.GasMnemonic = "movntdqa",
			.Description = "movntdqa xmm, m128",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M128,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse41,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x38,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x2a,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128},
						.Rm = {OperandType::M128},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "movnti",
			.GasMnemonic = "movntil",
			.Description = "movntil m32, r32",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M32,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::R32,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::R32},
						.X = {OperandType::M32},
						.B = {OperandType::M32},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xc3,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M32},
						.Rm = {OperandType::M32},
						.Reg = {OperandType::R32},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "movnti",
			.GasMnemonic = "movntiq",
			.Description = "movntiq m64, r64",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M64,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::R64,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = true,
						.R = {OperandType::R64},
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.IsMandatory = true,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xc3,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
						.Reg = {OperandType::R64},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "movntpd",
			.GasMnemonic = "movntpd",
			.Description = "movntpd m128, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M128,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x2b,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128},
						.Rm = {OperandType::M128},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "movntps",
			.GasMnemonic = "movntps",
			.Description = "movntps m128, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M128,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x2b,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128},
						.Rm = {OperandType::M128},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "movntq",
			.GasMnemonic = "movntq",
			.Description = "movntq m64, mm",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M64,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::MmxExt,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Mm},
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xe7,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
						.Reg = {OperandType::Mm},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "movntsd",
			.GasMnemonic = "movntsd",
			.Description = "movntsd m64, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M64,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse4A,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0xf2,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x2b,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "movntss",
			.GasMnemonic = "movntss",
			.Description = "movntss m32, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M32,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse4A,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0xf3,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M32},
						.B = {OperandType::M32},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x2b,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M32},
						.Rm = {OperandType::M32},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "movq",
			.GasMnemonic = "movq",
			.Description = "movq r64, mm",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::R64,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Mmx,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = true,
						.R = {OperandType::Mm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::R64},
						.IsMandatory = true,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x7e,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R64},
						.Reg = {OperandType::Mm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "movq",
			.GasMnemonic = "movq",
			.Description = "movq r64, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::R64,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = true,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::R64},
						.IsMandatory = true,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x7e,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R64},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "movq",
			.GasMnemonic = "movq",
			.Description = "movq mm, r64",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::R64,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Mmx,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = true,
						.R = {OperandType::Mm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::R64},
						.IsMandatory = true,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x6e,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R64},
						.Reg = {OperandType::Mm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "movq",
			.GasMnemonic = "movq",
			.Description = "movq mm, mm",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Mmx,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Mm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Mm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x6f,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Mm},
						.Reg = {OperandType::Mm},
					},
				},
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Mm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Mm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x7f,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Mm},
						.Reg = {OperandType::Mm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "movq",
			.GasMnemonic = "movq",
			.Description = "movq mm, m64",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M64,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Mmx,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Mm},
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x6f,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
						.Reg = {OperandType::Mm},
					},
				},
				Encoding
				{
					Rex
					{
						.W = true,
						.R = {OperandType::Mm},
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.IsMandatory = true,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x6e,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
						.Reg = {OperandType::Mm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "movq",
			.GasMnemonic = "movq",
			.Description = "movq xmm, r64",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::R64,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = true,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::R64},
						.IsMandatory = true,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x6e,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R64},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "movq",
			.GasMnemonic = "movq",
			.Description = "movq xmm, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0xf3,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x7e,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::Xmm},
					},
				},
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xd6,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "movq",
			.GasMnemonic = "movq",
			.Description = "movq xmm, m64",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M64,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0xf3,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x7e,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
						.Reg = {OperandType::Xmm},
					},
				},
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = true,
						.R = {OperandType::Xmm},
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.IsMandatory = true,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x6e,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "movq",
			.GasMnemonic = "movq",
			.Description = "movq m64, mm",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M64,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Mmx,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Mm},
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x7f,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
						.Reg = {OperandType::Mm},
					},
				},
				Encoding
				{
					Rex
					{
						.W = true,
						.R = {OperandType::Mm},
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.IsMandatory = true,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x7e,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
						.Reg = {OperandType::Mm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "movq",
			.GasMnemonic = "movq",
			.Description = "movq m64, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M64,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xd6,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
						.Reg = {OperandType::Xmm},
					},
				},
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = true,
						.R = {OperandType::Xmm},
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.IsMandatory = true,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x7e,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "movq2dq",
			.GasMnemonic = "movq2dq",
			.Description = "movq2dq xmm, mm",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0xf3,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Mm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xd6,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Mm},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "movsd",
			.GasMnemonic = "movsd",
			.Description = "movsd xmm, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0xf2,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x10,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::Xmm},
					},
				},
				Encoding
				{
					Prefix
					{
						.Value = 0xf2,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x11,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "movsd",
			.GasMnemonic = "movsd",
			.Description = "movsd xmm, m64",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M64,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0xf2,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x10,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "movsd",
			.GasMnemonic = "movsd",
			.Description = "movsd m64, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M64,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0xf2,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x11,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "movshdup",
			.GasMnemonic = "movshdup",
			.Description = "movshdup xmm, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse3,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0xf3,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x16,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "movshdup",
			.GasMnemonic = "movshdup",
			.Description = "movshdup xmm, m128",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M128,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse3,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0xf3,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x16,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128},
						.Rm = {OperandType::M128},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "movsldup",
			.GasMnemonic = "movsldup",
			.Description = "movsldup xmm, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse3,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0xf3,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x12,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "movsldup",
			.GasMnemonic = "movsldup",
			.Description = "movsldup xmm, m128",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M128,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse3,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0xf3,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x12,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128},
						.Rm = {OperandType::M128},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "movss",
			.GasMnemonic = "movss",
			.Description = "movss xmm, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0xf3,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x10,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::Xmm},
					},
				},
				Encoding
				{
					Prefix
					{
						.Value = 0xf3,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x11,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "movss",
			.GasMnemonic = "movss",
			.Description = "movss xmm, m32",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M32,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0xf3,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M32},
						.B = {OperandType::M32},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x10,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M32},
						.Rm = {OperandType::M32},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "movss",
			.GasMnemonic = "movss",
			.Description = "movss m32, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M32,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0xf3,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M32},
						.B = {OperandType::M32},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x11,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M32},
						.Rm = {OperandType::M32},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "movsx",
			.GasMnemonic = "movsbw",
			.Description = "movsbw r16, r8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::R16,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::R8,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = false,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::R16},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::R8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xbe,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R8},
						.Reg = {OperandType::R16},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "movsx",
			.GasMnemonic = "movsbw",
			.Description = "movsbw r16, m8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::R16,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M8,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = false,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::R16},
						.X = {OperandType::M8},
						.B = {OperandType::M8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xbe,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M8},
						.Rm = {OperandType::M8},
						.Reg = {OperandType::R16},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "movsx",
			.GasMnemonic = "movsbl",
			.Description = "movsbl r32, r8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::R32,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::R8,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::R32},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::R8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xbe,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R8},
						.Reg = {OperandType::R32},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "movsx",
			.GasMnemonic = "movswl",
			.Description = "movswl r32, r16",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::R32,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::R16,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::R32},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::R16},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xbf,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R16},
						.Reg = {OperandType::R32},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "movsx",
			.GasMnemonic = "movsbl",
			.Description = "movsbl r32, m8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::R32,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M8,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::R32},
						.X = {OperandType::M8},
						.B = {OperandType::M8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xbe,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M8},
						.Rm = {OperandType::M8},
						.Reg = {OperandType::R32},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "movsx",
			.GasMnemonic = "movswl",
			.Description = "movswl r32, m16",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::R32,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M16,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::R32},
						.X = {OperandType::M16},
						.B = {OperandType::M16},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xbf,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M16},
						.Rm = {OperandType::M16},
						.Reg = {OperandType::R32},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "movsx",
			.GasMnemonic = "movsbq",
			.Description = "movsbq r64, r8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::R64,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::R8,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = true,
						.R = {OperandType::R64},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::R8},
						.IsMandatory = true,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xbe,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R8},
						.Reg = {OperandType::R64},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "movsx",
			.GasMnemonic = "movswq",
			.Description = "movswq r64, r16",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::R64,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::R16,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = true,
						.R = {OperandType::R64},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::R16},
						.IsMandatory = true,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xbf,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R16},
						.Reg = {OperandType::R64},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "movsx",
			.GasMnemonic = "movsbq",
			.Description = "movsbq r64, m8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::R64,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M8,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = true,
						.R = {OperandType::R64},
						.X = {OperandType::M8},
						.B = {OperandType::M8},
						.IsMandatory = true,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xbe,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M8},
						.Rm = {OperandType::M8},
						.Reg = {OperandType::R64},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "movsx",
			.GasMnemonic = "movswq",
			.Description = "movswq r64, m16",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::R64,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M16,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = true,
						.R = {OperandType::R64},
						.X = {OperandType::M16},
						.B = {OperandType::M16},
						.IsMandatory = true,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xbf,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M16},
						.Rm = {OperandType::M16},
						.Reg = {OperandType::R64},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "movsxd",
			.GasMnemonic = "movslq",
			.Description = "movslq r64, r32",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::R64,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::R32,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = true,
						.R = {OperandType::R64},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::R32},
						.IsMandatory = true,
					},
					OpCode
					{
						.Value = 0x63,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R32},
						.Reg = {OperandType::R64},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "movsxd",
			.GasMnemonic = "movslq",
			.Description = "movslq r64, m32",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::R64,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M32,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = true,
						.R = {OperandType::R64},
						.X = {OperandType::M32},
						.B = {OperandType::M32},
						.IsMandatory = true,
					},
					OpCode
					{
						.Value = 0x63,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M32},
						.Rm = {OperandType::M32},
						.Reg = {OperandType::R64},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "movupd",
			.GasMnemonic = "movupd",
			.Description = "movupd xmm, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x10,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::Xmm},
					},
				},
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x11,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "movupd",
			.GasMnemonic = "movupd",
			.Description = "movupd xmm, m128",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M128,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x10,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128},
						.Rm = {OperandType::M128},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "movupd",
			.GasMnemonic = "movupd",
			.Description = "movupd m128, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M128,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x11,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128},
						.Rm = {OperandType::M128},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "movups",
			.GasMnemonic = "movups",
			.Description = "movups xmm, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x10,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::Xmm},
					},
				},
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x11,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "movups",
			.GasMnemonic = "movups",
			.Description = "movups xmm, m128",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M128,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x10,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128},
						.Rm = {OperandType::M128},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "movups",
			.GasMnemonic = "movups",
			.Description = "movups m128, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M128,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x11,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128},
						.Rm = {OperandType::M128},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "movzx",
			.GasMnemonic = "movzbw",
			.Description = "movzbw r16, r8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::R16,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::R8,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = false,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::R16},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::R8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xb6,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R8},
						.Reg = {OperandType::R16},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "movzx",
			.GasMnemonic = "movzbw",
			.Description = "movzbw r16, m8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::R16,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M8,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = false,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::R16},
						.X = {OperandType::M8},
						.B = {OperandType::M8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xb6,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M8},
						.Rm = {OperandType::M8},
						.Reg = {OperandType::R16},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "movzx",
			.GasMnemonic = "movzbl",
			.Description = "movzbl r32, r8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::R32,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::R8,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::R32},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::R8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xb6,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R8},
						.Reg = {OperandType::R32},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "movzx",
			.GasMnemonic = "movzwl",
			.Description = "movzwl r32, r16",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::R32,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::R16,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::R32},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::R16},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xb7,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R16},
						.Reg = {OperandType::R32},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "movzx",
			.GasMnemonic = "movzbl",
			.Description = "movzbl r32, m8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::R32,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M8,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::R32},
						.X = {OperandType::M8},
						.B = {OperandType::M8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xb6,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M8},
						.Rm = {OperandType::M8},
						.Reg = {OperandType::R32},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "movzx",
			.GasMnemonic = "movzwl",
			.Description = "movzwl r32, m16",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::R32,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M16,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::R32},
						.X = {OperandType::M16},
						.B = {OperandType::M16},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xb7,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M16},
						.Rm = {OperandType::M16},
						.Reg = {OperandType::R32},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "movzx",
			.GasMnemonic = "movzbq",
			.Description = "movzbq r64, r8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::R64,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::R8,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = true,
						.R = {OperandType::R64},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::R8},
						.IsMandatory = true,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xb6,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R8},
						.Reg = {OperandType::R64},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "movzx",
			.GasMnemonic = "movzwq",
			.Description = "movzwq r64, r16",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::R64,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::R16,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = true,
						.R = {OperandType::R64},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::R16},
						.IsMandatory = true,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xb7,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R16},
						.Reg = {OperandType::R64},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "movzx",
			.GasMnemonic = "movzbq",
			.Description = "movzbq r64, m8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::R64,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M8,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = true,
						.R = {OperandType::R64},
						.X = {OperandType::M8},
						.B = {OperandType::M8},
						.IsMandatory = true,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xb6,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M8},
						.Rm = {OperandType::M8},
						.Reg = {OperandType::R64},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "movzx",
			.GasMnemonic = "movzwq",
			.Description = "movzwq r64, m16",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::R64,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M16,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = true,
						.R = {OperandType::R64},
						.X = {OperandType::M16},
						.B = {OperandType::M16},
						.IsMandatory = true,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xb7,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M16},
						.Rm = {OperandType::M16},
						.Reg = {OperandType::R64},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "mpsadbw",
			.GasMnemonic = "mpsadbw",
			.Description = "mpsadbw xmm, xmm, imm8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Imm8,
					.IsInput = false,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse41,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x3a,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x42,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::Xmm},
					},
					ImmediateScalar
					{
						.Size = 1,
						.Value = {OperandType::Imm8},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "mpsadbw",
			.GasMnemonic = "mpsadbw",
			.Description = "mpsadbw xmm, m128, imm8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M128,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Imm8,
					.IsInput = false,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse41,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x3a,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x42,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128},
						.Rm = {OperandType::M128},
						.Reg = {OperandType::Xmm},
					},
					ImmediateScalar
					{
						.Size = 1,
						.Value = {OperandType::Imm8},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "mul",
			.GasMnemonic = "mulb",
			.Description = "mulb r8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::R8,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
				ImplicitRegisterOperand::Al,
			},
			.ImplicitOutputs =
			{
				ImplicitRegisterOperand::Ax,
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::R8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf6,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R8},
						.Reg = {UINT64_C(0x4)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "mul",
			.GasMnemonic = "mulw",
			.Description = "mulw r16",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::R16,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
				ImplicitRegisterOperand::Ax,
			},
			.ImplicitOutputs =
			{
				ImplicitRegisterOperand::Dx,
				ImplicitRegisterOperand::Ax,
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = false,
					},
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::R16},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf7,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R16},
						.Reg = {UINT64_C(0x4)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "mul",
			.GasMnemonic = "mull",
			.Description = "mull r32",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::R32,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
				ImplicitRegisterOperand::Eax,
			},
			.ImplicitOutputs =
			{
				ImplicitRegisterOperand::Edx,
				ImplicitRegisterOperand::Eax,
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::R32},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf7,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R32},
						.Reg = {UINT64_C(0x4)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "mul",
			.GasMnemonic = "mulq",
			.Description = "mulq r64",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::R64,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
				ImplicitRegisterOperand::Rax,
			},
			.ImplicitOutputs =
			{
				ImplicitRegisterOperand::Rax,
				ImplicitRegisterOperand::Rdx,
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = true,
						.R = {UINT64_C(0x0)},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::R64},
						.IsMandatory = true,
					},
					OpCode
					{
						.Value = 0xf7,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R64},
						.Reg = {UINT64_C(0x4)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "mul",
			.GasMnemonic = "mulb",
			.Description = "mulb m8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M8,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
				ImplicitRegisterOperand::Al,
			},
			.ImplicitOutputs =
			{
				ImplicitRegisterOperand::Ax,
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {OperandType::M8},
						.B = {OperandType::M8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf6,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M8},
						.Rm = {OperandType::M8},
						.Reg = {UINT64_C(0x4)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "mul",
			.GasMnemonic = "mulw",
			.Description = "mulw m16",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M16,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
				ImplicitRegisterOperand::Ax,
			},
			.ImplicitOutputs =
			{
				ImplicitRegisterOperand::Dx,
				ImplicitRegisterOperand::Ax,
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = false,
					},
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {OperandType::M16},
						.B = {OperandType::M16},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf7,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M16},
						.Rm = {OperandType::M16},
						.Reg = {UINT64_C(0x4)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "mul",
			.GasMnemonic = "mull",
			.Description = "mull m32",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M32,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
				ImplicitRegisterOperand::Eax,
			},
			.ImplicitOutputs =
			{
				ImplicitRegisterOperand::Edx,
				ImplicitRegisterOperand::Eax,
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {OperandType::M32},
						.B = {OperandType::M32},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf7,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M32},
						.Rm = {OperandType::M32},
						.Reg = {UINT64_C(0x4)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "mul",
			.GasMnemonic = "mulq",
			.Description = "mulq m64",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M64,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
				ImplicitRegisterOperand::Rax,
			},
			.ImplicitOutputs =
			{
				ImplicitRegisterOperand::Rax,
				ImplicitRegisterOperand::Rdx,
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = true,
						.R = {UINT64_C(0x0)},
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.IsMandatory = true,
					},
					OpCode
					{
						.Value = 0xf7,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
						.Reg = {UINT64_C(0x4)},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "mulpd",
			.GasMnemonic = "mulpd",
			.Description = "mulpd xmm, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x59,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "mulpd",
			.GasMnemonic = "mulpd",
			.Description = "mulpd xmm, m128",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M128,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x59,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128},
						.Rm = {OperandType::M128},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "mulps",
			.GasMnemonic = "mulps",
			.Description = "mulps xmm, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x59,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "mulps",
			.GasMnemonic = "mulps",
			.Description = "mulps xmm, m128",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M128,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x59,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128},
						.Rm = {OperandType::M128},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "mulsd",
			.GasMnemonic = "mulsd",
			.Description = "mulsd xmm, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0xf2,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x59,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "mulsd",
			.GasMnemonic = "mulsd",
			.Description = "mulsd xmm, m64",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M64,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0xf2,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x59,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

};
}
