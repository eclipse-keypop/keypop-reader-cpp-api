/**************************************************************************************************
 * Copyright (c) 2024 Calypso Networks Association https://calypsonet.org/                        *
 *                                                                                                *
 * This program and the accompanying materials are made available under the                       *
 * terms of the MIT License which is available at https://opensource.org/licenses/MIT.            *
 *                                                                                                *
 * SPDX-License-Identifier: MIT                                                                   *
 **************************************************************************************************/

#pragma once

#include <memory>
#include <string>

#include "keypop/reader/selection/BasicCardSelector.hpp"
#include "keypop/reader/selection/CardSelectionManager.hpp"
#include "keypop/reader/selection/IsoCardSelector.hpp"

namespace keypop {
namespace reader {

using keypop::reader::selection::BasicCardSelector;
using keypop::reader::selection::CardSelectionManager;
using keypop::reader::selection::IsoCardSelector;

/**
 * Reader API Factory.
 *
 * @since 2.0.0
 */
class ReaderApiFactory {
public:
    /**
     * Returns a new instance of CardSelectionManager.
     *
     * @return A new instance of CardSelectionManager.
     * @since 2.0.0
     */
    virtual std::shared_ptr<CardSelectionManager> createCardSelectionManager() = 0;

    /**
     * Returns a new instance of {@link BasicCardSelector}.
     *
     * @return A new instance of {@link BasicCardSelector}.
     * @since 2.0.0
     */
    virtual std::shared_ptr<BasicCardSelector> createBasicCardSelector() = 0;

    /**
     * Returns a new instance of {@link IsoCardSelector}.
     *
     * @return A new instance of {@link IsoCardSelector}.
     * @since 2.0.0
     */
    virtual std::shared_ptr<IsoCardSelector> createIsoCardSelector() = 0;
};

} /* namespace reader */
} /* namespace keypop */
